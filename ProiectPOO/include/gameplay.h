#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "nava.h"
#include "fundal.h"
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include "glont_rotund.h"
#include "glont_linie.h"
#include "glont_fusiform.h"
#include "armament_baza.h"
#include "arma_plus_un_glont.h"
#include "arma_minus_un_glont.h"
#include "generator_adversari.h"


class gameplay
{
    sf::RenderWindow* fereastra=NULL;
    fundal fundal_joc;
    nava nava_mea;
    static sf::Vector2f dimensiune_virtuala_fereastra;
    sf::Clock frame_clock;
    sf::Time timp;
    sf::Event e;
    friend class gameplay_biulder;
    std::set<glont*> gloante={};
    std::set<armament_baza_netemplate*> arme={};
    armament_baza_netemplate* arma_activa=NULL;
    int* nr_gloante=NULL;
    std::set<adversar*> adversari={};
    generator_adversari* generator_adv=NULL;
    int pauza=0;
    bool game_over = true;
    sf::Font font;
    int font_size=50;
    sf::Text easy;
    sf::Text medium;
    sf::Text hard;

public:
    static sf::Vector2f get_dimensiuni_virtuale_fereastra();
    gameplay(sf::RenderWindow* w=NULL);
    ~gameplay();
    gameplay(const gameplay&);
    friend void swap(gameplay&,gameplay&);
    gameplay& operator=(gameplay);
    void play();
    void init();
    void generare_gloante();
    void generare_armament();
    void miscare_armament();
    void desenare_armament();
    void actualizare_arma();
    void eliberare_armament();
    void desenare_adversari()const;
    void gameover();
    void eliberare_memorie();
    void img_pauza();
    void meniu_joc();
};

class gameplay_biulder
{
    gameplay g;
public:
    explicit gameplay_biulder(sf::RenderWindow* w);
    gameplay_biulder& init_fereastra();

    gameplay_biulder& init_fundal(const sf::Color& culoare=sf::Color(0,0,0));

    gameplay_biulder& init_nava(const sf::Color& culoare=sf::Color(255,255,0),const sf::Color& culoare_gloante_=sf::Color(0,255,0));

    gameplay build();
};

#endif // GAMEPLAY_H
