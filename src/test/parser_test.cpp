#define BOOST_TEST_MODULE parser
#include <boost/test/included/unit_test.hpp>
#include <boost/foreach.hpp>
#include <boost/assign.hpp>

#include "Parser.h"

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
            "1400;29;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;3;0;0;0;0; 0;38;0;0;0;0;0;0\r\n"
            // Betriebsstunden
            "1450;9;3628317;2161;1678;3121663;2162;1443;372727; 0;6230122\r\n"
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

            ( "Temperaturwerte", boost::assign::list_of<parser::value>
                ("Heizkreis_Ist_Vorlauftemperatur", "12")
                ("Heizkreis_Ist_Ruecklauftemperatur", "256")
                ("Heizkreis_Soll_Ruecklauftemperatur", "254")
                ("Heissgastemperatur", "267")
                ("Aussentemperatur", "261")
                ("Brauchwarmwasser_Ist_Temperatur", "50")
                ("Brauchwarmwasser_Soll_Temperatur", "445")
                ("Waermequellen_Eintrittstemperatur", "450")
                ("Waermequellen_Austrittstemperatur", "125")
                ("Mischkreis_1_Ist_Vorlauftemperatur", "121")
                ("Mischkreis_1_Soll_Vorlauftemperatur", "750")
                ("Raumstation", "200")
            )
            ("Wärmepumpeneingänge", boost::assign::list_of<parser::value>
                ("Abtau_Soledruck_Durchfluss", "0b01")
                ("Sperrzeit_vom_EVU", "0b01")
                ("Hochdruckpressostat", "0b01")
                ("Motorschutz", "0b01")
                ("Niederdruckpressostat", "0b01")
                ("Anschluss_einer_Fremdstromanode", "0b01")
            )
            ("Wärmepumpenausgänge", boost::assign::list_of<parser::value>
                ("Abtauventil", "0b01")
                ("Brauchwarmwasserumwaelzpumpe", "0b01")
                ("Fussbodenheizungsumwaelzpumpe", "0b01")
                ("Heizungsumwaelzpumpe", "0b01")
                ("Mischer_1_Auf", "0b01")
                ("Mischer_1_Zu", "0b01")
                ("Ventilation_des_Waermepumpengehaeuses", "0b01")
                ("Ventilator_Brunnen_oder_Soleumwaelzpumpe", "0b01")
                ("Verdichter_1_in_Waermepumpe", "0b01")
                ("Verdichter_2_in_Waermepumpe", "0b01")
                ("Zusatzumwaelzpumpe_Zirkulationspumpe", " 0b01")
                ("Zweiter_Waermeerzeuger_1", "0b01")
                ("Zweiter_Waermeerzeuger_2_Sammelstoerung", "0b01")
            )
            ("Ablaufzeiten", boost::assign::list_of<parser::value>
                ("Waermepumpe", "$$")
                ("Zweiter_Waermeerzeuger_1", "$$")
                ("Zweiter_Waermeerzeuger_2", "$$")
                ("Netzeinschaltverzoegerung", "$$")
                ("Standzeit_Schaltspielsperre", "$$")
                ("Einschaltverzoegerung_Schaltspielsperre", "$$")
                ("Verdichter_Standzeit", "$$")
                ("Heizungsregler_Mehr_Zeit", "$$")
                ("Heizungsregler_Weniger_Zeit", "$$")
                ("Thermische_Desinfektion", "$$")
                ("Sperre_Brauchwarmwasser", "$$")
            )
            ("Betriebstunden", boost::assign::list_of<parser::value>
                ("Betriebsstunden_Verdichter_1", "0u32")
                ("Impulse_Verdichter_1", "0u32")
                ("Durchschnittliche_Laufzeit_Verdichter_1", "0u32")
                ("Betriebsstunden_Verdichter_2", "0u32")
                ("Impulse_Verdichter_2", "0u32")
                ("Durchschnittliche_Laufzeit_Verdichter_2", "0u32")
                ("Betriebsstunden_Zweiter_Waermeerzeuger_ 1", "0u32")
                ("Betriebsstunden_Zweiter_Waermeerzeuger_ 2", "0u32")
                ("Betriebsstunden_Waermepumpe", "0u32")
            )
            ("Fehler1", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Fehler2", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Fehler3", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Fehler4", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Fehler5", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Abschaltungen1", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Abschaltungen2", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Abschaltungen3", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Abschaltungen4", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Abschaltungen5", boost::assign::list_of<parser::value>
                ("Code", "$$")
                ("Datum", "$$")
                ("Uhrzeit", "$$")
            )
            ("Anlagenstatus", boost::assign::list_of<parser::value>
                ("Waermepumpentyp", "$$")
                ("Software_Version", "$$")
                ("Bivalenzstufe", "0b01")
                ("Aktueller_Betriebszustand", "0b01")
                ("Startdatum", "$$")
                ("Startuhrzeit", "$$")
                ("Compact", "0b01")
                ("Comfort", "0b01")
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
    parser::section_list_t::const_iterator s_end;

    BOOST_FOREACH(const parser::section& section, result)
    {
        const parser::section& section_expected = *s_it++;
        if(s_it == s_end)
        {
            BOOST_CHECK_MESSAGE(s_it != s_end, "more sections than expected");
            continue;
        }

        BOOST_CHECK_EQUAL(section.name, section_expected.name);

        parser::value_list_t::const_iterator v_it = section_expected.values.begin();
        parser::value_list_t::const_iterator v_end;

        BOOST_FOREACH(const parser::value& value, section.values)
        {
            const parser::value& value_expected = *v_it++;

            if(v_it == v_end)
            {
                BOOST_CHECK_MESSAGE(v_it != v_end, "more values than expected");
                continue;
            }

            BOOST_CHECK_EQUAL(value.key, value_expected.key);
            BOOST_CHECK_EQUAL(value.val, value_expected.val);
        }

        BOOST_CHECK_MESSAGE(v_it == parser::value_list_t::iterator(), "expected more values" /* ": " << parser::value(*v_it) */);
    }
    BOOST_CHECK_MESSAGE(s_it == parser::section_list_t::iterator(), "expected more sections" /* ": " << *s_it */);
}

BOOST_AUTO_TEST_SUITE_END()
