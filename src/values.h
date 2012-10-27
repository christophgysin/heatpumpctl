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
        ("1450", "Betriebstunden")
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
        ;
}
