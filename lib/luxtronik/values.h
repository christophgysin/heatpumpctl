#pragma once
#include <string>
#include <map>
#include <vector>
#include <boost/assign.hpp>

namespace values {

    typedef std::map<std::string, std::string> headings_t;
    typedef std::map<std::string, std::string> subheadings_t;
    typedef std::vector<std::string> names_t;
    typedef std::map<std::string, names_t> names_map_t;

    headings_t headings = boost::assign::map_list_of
        ("1100", "Temperaturwerte")
        ("1200", "Wärmepumpeneingänge")
        ("1300", "Wärmepumpenausgänge")
        ("1400", "Ablaufzeiten")
        ("1450", "Betriebsstunden")
        ("1500", "Fehler1")
        ("1501", "Fehler2")
        ("1502", "Fehler3")
        ("1503", "Fehler4")
        ("1504", "Fehler5")
        ("1600", "Abschaltungen1")
        ("1601", "Abschaltungen2")
        ("1602", "Abschaltungen3")
        ("1603", "Abschaltungen4")
        ("1604", "Abschaltungen5")
        ("1700", "Anlagenstatus")
        ;

    subheadings_t subheadings = boost::assign::map_list_of
        ("1500", "Fehler")
        ("1600", "Abschaltungen")
        ;

    names_map_t names = boost::assign::list_of<names_map_t::value_type>
        ("Temperaturwerte", boost::assign::list_of
            ("Heizkreis_Ist_Vorlauftemperatur")
            ("Heizkreis_Ist_Ruecklauftemperatur")
            ("Heizkreis_Soll_Ruecklauftemperatur")
            ("Heissgastemperatur")
            ("Aussentemperatur")
            ("Brauchwarmwasser_Ist_Temperatur")
            ("Brauchwarmwasser_Soll_Temperatur")
            ("Waermequellen_Eintrittstemperatur")
            ("Waermequellen_Austrittstemperatur")
            ("Mischkreis_1_Ist_Vorlauftemperatur")
            ("Mischkreis_1_Soll_Vorlauftemperatur")
            ("Raumstation")
        )
        ("Wärmepumpeneingänge", boost::assign::list_of
            ("Abtau_Soledruck_Durchfluss")
            ("Sperrzeit_vom_EVU")
            ("Hochdruckpressostat")
            ("Motorschutz")
            ("Niederdruckpressostat")
            ("Anschluss_einer_Fremdstromanode")
        )
        ("Wärmepumpenausgänge", boost::assign::list_of
            ("Abtauventil")
            ("Brauchwarmwasserumwaelzpumpe")
            ("Fussbodenheizungsumwaelzpumpe")
            ("Heizungsumwaelzpumpe")
            ("Mischer_1_Auf")
            ("Mischer_1_Zu")
            ("Ventilation_des_Waermepumpengehaeuses")
            ("Ventilator_Brunnen_oder_Soleumwaelzpumpe")
            ("Verdichter_1_in_Waermepumpe")
            ("Verdichter_2_in_Waermepumpe")
            ("Zusatzumwaelzpumpe_Zirkulationspumpe")
            ("Zweiter_Waermeerzeuger_1")
            ("Zweiter_Waermeerzeuger_2_Sammelstoerung")
        )
        ("Ablaufzeiten", boost::assign::list_of
            ("Waermepumpe")
            ("Zweiter_Waermeerzeuger_1")
            ("Zweiter_Waermeerzeuger_2")
            ("Netzeinschaltverzoegerung")
            ("Standzeit_Schaltspielsperre")
            ("Einschaltverzoegerung_Schaltspielsperre")
            ("Verdichter_Standzeit")
            ("Heizungsregler_Mehr_Zeit")
            ("Heizungsregler_Weniger_Zeit")
            ("Thermische_Desinfektion")
            ("Sperre_Brauchwarmwasser")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
            ("Unbekannter_Wert")
        )
        ("Betriebsstunden", boost::assign::list_of
            ("Betriebsstunden_Verdichter_1")
            ("Impulse_Verdichter_1")
            ("Durchschnittliche_Laufzeit_Verdichter_1")
            ("Betriebsstunden_Verdichter_2")
            ("Impulse_Verdichter_2")
            ("Durchschnittliche_Laufzeit_Verdichter_2")
            ("Betriebsstunden_Zweiter_Waermeerzeuger_1")
            ("Betriebsstunden_Zweiter_Waermeerzeuger_2")
            ("Betriebsstunden_Waermepumpe")
        )
        ("Fehler1", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Fehler2", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Fehler3", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Fehler4", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Fehler5", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Abschaltungen1", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Abschaltungen2", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Abschaltungen3", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Abschaltungen4", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Abschaltungen5", boost::assign::list_of
            ("Code")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
        )
        ("Anlagenstatus", boost::assign::list_of
            ("Waermepumpentyp")
            ("Software_Version")
            ("Bivalenzstufe")
            ("Aktueller_Betriebszustand")
            ("Tag")
            ("Monat")
            ("Jahr")
            ("Stunde")
            ("Minute")
            ("Sekunde")
            ("Compact")
            ("Comfort")
        )
        ;
}
