#define BOOST_TEST_MODULE parser
#include <boost/test/included/unit_test.hpp>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>

#include <luxtronik/Parser.h>

struct fixture {

    std::string s;
    parser::result_t expected;
    Parser p;

    fixture() :
        s(
            // Header
            "1800;8\r\n"
            // Temperaturwerte2
            "1100;12;256;254;267;261;50;445;450;125;121;750;200;0\r\n"
            // Status WP-Eingänge
            "1200;6;1;1;0;1;1;0\r\n"
            // Status WP-Ausgänge
            "1300;13;0;0;1;1;0;1;0;0;0;0;0;0;0\r\n"
            // Ablaufzeiten
            "1400;29;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;3;0;0;0;0;0;38;0;0;0;0;0;0\r\n"
            // Betriebsstunden
            "1450;9;3628317;2161;1678;3121663;2162;1443;372727;0;6230122\r\n"
            // Sub-Header
            "1500;5\r\n"
            // Fehlermeldung 1 (z.B. Fehler 709, vom 22.11.2008 11.54 Uhr)
            "1500;1500;6;709;22;11;8;11;54\r\n"
            // Fehlermeldung 2
            "1500;1501;6;715;22;11;8;12;4\r\n"
            // Fehlermeldung 3
            "1500;1502;6;709;22;11;8;12;4\r\n"
            // Fehlermeldung 4
            "1500;1503;6;711;11;12;8;20;24\r\n"
            // Fehlermeldung 5
            "1500;1504;6;708;13;12;8;14;9\r\n"
            // Sub-Footer
            "1500;5\r\n"
            // Sub-Header
            "1600;5\r\n"
            // Abschaltung 1 (z.B. Abschaltgrund 010, vom 19.12.2008 12.32 Uhr)
            "1600;1600;6;010;19;12;8;12;32\r\n"
            // Abschaltung 2
            "1600;1601;6;010;19;12;8;14;54\r\n"
            // Abschaltung 3
            "1600;1602;6;010;19;12;8;17;10\r\n"
            // Abschaltung 4
            "1600;1603;6;010;19;12;8;19;31\r\n"
            // Abschaltung 5
            "1600;1604;6;010;19;12;8;21;14\r\n"
            // Sub-Footer
            "1600;5\r\n"
            // Anlagenstatus
            "1700;12;2;V2.33;1;5;19;12;8;10;42;12;0;1\r\n"
            // Footer
            "1800;8\r\n"
        )
    {
        expected = boost::assign::list_of<parser::section>

            // "1100;12;256;254;267;261;50;445;450;125;121;750;200;0\r\n"
            ( "Temperaturwerte", boost::assign::list_of<parser::value>
                ("Heizkreis_Ist_Vorlauftemperatur", "256")
                ("Heizkreis_Ist_Ruecklauftemperatur", "254")
                ("Heizkreis_Soll_Ruecklauftemperatur", "267")
                ("Heissgastemperatur", "261")
                ("Aussentemperatur", "50")
                ("Brauchwarmwasser_Ist_Temperatur", "445")
                ("Brauchwarmwasser_Soll_Temperatur", "450")
                ("Waermequellen_Eintrittstemperatur", "125")
                ("Waermequellen_Austrittstemperatur", "121")
                ("Mischkreis_1_Ist_Vorlauftemperatur", "750")
                ("Mischkreis_1_Soll_Vorlauftemperatur", "200")
                ("Raumstation", "0")
            )
            // "1200;6;1;1;0;1;1;0\r\n"
            ("Wärmepumpeneingänge", boost::assign::list_of<parser::value>
                ("Abtau_Soledruck_Durchfluss", "1")
                ("Sperrzeit_vom_EVU", "1")
                ("Hochdruckpressostat", "0")
                ("Motorschutz", "1")
                ("Niederdruckpressostat", "1")
                ("Anschluss_einer_Fremdstromanode", "0")
            )
            // "1300;13;0;0;1;1;0;1;0;0;0;0;0;0;0\r\n"
            ("Wärmepumpenausgänge", boost::assign::list_of<parser::value>
                ("Abtauventil", "0")
                ("Brauchwarmwasserumwaelzpumpe", "0")
                ("Fussbodenheizungsumwaelzpumpe", "1")
                ("Heizungsumwaelzpumpe", "1")
                ("Mischer_1_Auf", "0")
                ("Mischer_1_Zu", "1")
                ("Ventilation_des_Waermepumpengehaeuses", "0")
                ("Ventilator_Brunnen_oder_Soleumwaelzpumpe", "0")
                ("Verdichter_1_in_Waermepumpe", "0")
                ("Verdichter_2_in_Waermepumpe", "0")
                ("Zusatzumwaelzpumpe_Zirkulationspumpe", "0")
                ("Zweiter_Waermeerzeuger_1", "0")
                ("Zweiter_Waermeerzeuger_2_Sammelstoerung", "0")
            )
            // "1400;29;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;3;0;0;0;0;0;38;0;0;0;0;0;0\r\n"
            ("Ablaufzeiten", boost::assign::list_of<parser::value>
                ("Waermepumpe", "0")
                ("Zweiter_Waermeerzeuger_1", "0")
                ("Zweiter_Waermeerzeuger_2", "0")
                ("Netzeinschaltverzoegerung", "0")
                ("Standzeit_Schaltspielsperre", "0")
                ("Einschaltverzoegerung_Schaltspielsperre", "0")
                ("Verdichter_Standzeit", "0")
                ("Heizungsregler_Mehr_Zeit", "0")
                ("Heizungsregler_Weniger_Zeit", "0")
                ("Thermische_Desinfektion", "0")
                ("Sperre_Brauchwarmwasser", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "1")
                ("Unbekannter_Wert", "1")
                ("Unbekannter_Wert", "3")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "38")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
                ("Unbekannter_Wert", "0")
            )
            // "1450;9;3628317;2161;1678;3121663;2162;1443;372727;0;6230122\r\n"
            ("Betriebsstunden", boost::assign::list_of<parser::value>
                ("Betriebsstunden_Verdichter_1", "3628317")
                ("Impulse_Verdichter_1", "2161")
                ("Durchschnittliche_Laufzeit_Verdichter_1", "1678")
                ("Betriebsstunden_Verdichter_2", "3121663")
                ("Impulse_Verdichter_2", "2162")
                ("Durchschnittliche_Laufzeit_Verdichter_2", "1443")
                ("Betriebsstunden_Zweiter_Waermeerzeuger_1", "372727")
                ("Betriebsstunden_Zweiter_Waermeerzeuger_2", "0")
                ("Betriebsstunden_Waermepumpe", "6230122")
            )
            // "1500;1500;6;709;22;11;8;11;54\r\n"
            ("Fehler1", boost::assign::list_of<parser::value>
                ("Code", "709")
                ("Tag", "22")
                ("Monat", "11")
                ("Jahr", "8")
                ("Stunde", "11")
                ("Minute", "54")
            )
            // "1500;1501;6;715;22;11;8;12;4\r\n"
            ("Fehler2", boost::assign::list_of<parser::value>
                ("Code", "715")
                ("Tag", "22")
                ("Monat", "11")
                ("Jahr", "8")
                ("Stunde", "12")
                ("Minute", "4")
            )
            // "1500;1502;6;709;22;11;8;12;4\r\n"
            ("Fehler3", boost::assign::list_of<parser::value>
                ("Code", "709")
                ("Tag", "22")
                ("Monat", "11")
                ("Jahr", "8")
                ("Stunde", "12")
                ("Minute", "4")
            )
            // "1500;1503;6;711;11;12;8;20;24\r\n"
            ("Fehler4", boost::assign::list_of<parser::value>
                ("Code", "711")
                ("Tag", "11")
                ("Monat", "12")
                ("Jahr", "8")
                ("Stunde", "20")
                ("Minute", "24")
            )
            // "1500;1504;6;708;13;12;8;14;9\r\n"
            ("Fehler5", boost::assign::list_of<parser::value>
                ("Code", "708")
                ("Tag", "13")
                ("Monat", "12")
                ("Jahr", "8")
                ("Stunde", "14")
                ("Minute", "9")
            )
            // "1600;1600;6;010;19;12;8;12;32\r\n"
            ("Abschaltungen1", boost::assign::list_of<parser::value>
                ("Code", "010")
                ("Tag", "19")
                ("Monat", "12")
                ("Jahr", "8")
                ("Stunde", "12")
                ("Minute", "32")
            )
            // "1600;1601;6;010;19;12;8;14;54\r\n"
            ("Abschaltungen2", boost::assign::list_of<parser::value>
                ("Code", "010")
                ("Tag", "19")
                ("Monat", "12")
                ("Jahr", "8")
                ("Stunde", "14")
                ("Minute", "54")
            )
            // "1600;1602;6;010;19;12;8;17;10\r\n"
            ("Abschaltungen3", boost::assign::list_of<parser::value>
                ("Code", "010")
                ("Tag", "19")
                ("Monat", "12")
                ("Jahr", "8")
                ("Stunde", "17")
                ("Minute", "10")
            )
            // "1600;1603;6;010;19;12;8;19;31\r\n"
            ("Abschaltungen4", boost::assign::list_of<parser::value>
                ("Code", "010")
                ("Tag", "19")
                ("Monat", "12")
                ("Jahr", "8")
                ("Stunde", "19")
                ("Minute", "31")
            )
            // "1600;1604;6;010;19;12;8;21;14\r\n"
            ("Abschaltungen5", boost::assign::list_of<parser::value>
                ("Code", "010")
                ("Tag", "19")
                ("Monat", "12")
                ("Jahr", "8")
                ("Stunde", "21")
                ("Minute", "14")
            )
            // "1700;12;2;V2.33;1;5;19;12;8;10;42;12;0;1\r\n"
            ("Anlagenstatus", boost::assign::list_of<parser::value>
                ("Waermepumpentyp", "2")
                ("Software_Version", "V2.33")
                ("Bivalenzstufe", "1")
                ("Aktueller_Betriebszustand", "5")
                ("Tag", "19")
                ("Monat", "12")
                ("Jahr", "8")
                ("Stunde", "10")
                ("Minute", "42")
                ("Sekunde", "12")
                ("Compact", "0")
                ("Comfort", "1")
            )
        ;
    }
};

BOOST_FIXTURE_TEST_SUITE(suite, fixture)

BOOST_AUTO_TEST_CASE(parse_strings)
{
    parser::result_t result = p.parse_strings(s);

    std::cout << result << std::endl;

    // now wouldn't that be nice...
    //BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(), expected.begin(), expected.end());

    parser::section_list_t::const_iterator s_it = expected.begin();
    parser::section_list_t::const_iterator s_end = expected.end();

    BOOST_FOREACH(const parser::section& section, result)
    {
        BOOST_MESSAGE("checking section: " << section.name);

        if(s_it == s_end)
        {
            BOOST_CHECK_MESSAGE(s_it != s_end, "more sections than expected");
            continue;
        }

        const parser::section& section_expected = *s_it++;

        BOOST_CHECK_EQUAL(section.name, section_expected.name);

        parser::value_list_t::const_iterator v_it = section_expected.values.begin();
        parser::value_list_t::const_iterator v_end = section_expected.values.end();

        BOOST_FOREACH(const parser::value& value, section.values)
        {
            if(v_it == v_end)
            {
                BOOST_CHECK_MESSAGE(v_it != v_end, "more values than expected");
                continue;
            }

            const parser::value& value_expected = *v_it++;

            BOOST_CHECK_EQUAL(value.key, value_expected.key);
            BOOST_CHECK_EQUAL(value.val, value_expected.val);
        }

        BOOST_CHECK_MESSAGE(v_it == v_end, "expected more values" /* ": " << parser::value(*v_it) */);
    }
    BOOST_CHECK_MESSAGE(s_it == s_end, "expected more sections" /* ": " << *s_it */);
}

BOOST_AUTO_TEST_SUITE_END()
