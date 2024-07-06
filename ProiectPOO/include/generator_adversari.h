#ifndef GENERATOR_ADVERSARI_H
#define GENERATOR_ADVERSARI_H

#include "adversar.h"
#include "nava.h"
#include <stdlib.h>

class generator_adversari
{
    sf::RenderWindow* fereastra=NULL;
    sf::Vector2f dimensiune_virtuala_fereastra;
    std::set<adversar*>* adversari=NULL;
    nava* nava_mea=NULL;
    sf::Vector2f viteza_adversari;
    std::set<glont*>* gloante=NULL;
    sf::Vector2f dimensiune_adversar=sf::Vector2f(0,0);
    sf::Color culoare_adversar=sf::Color(0,0,0);
    float padding=10;
    sf::Clock ceas;
    float hp_adversari=0;
    bool viteza_variabila=false;

public:
    generator_adversari(sf::RenderWindow*w=NULL,
                        const sf::Vector2f& dimens_v=sf::Vector2f(0,0),
                        std::set<adversar*>*adversari=NULL,
                        nava* nava_mea_=NULL,
                        const sf::Vector2f& viteza_adv=sf::Vector2f(0,0),
                        std::set<glont*>* gloante_=NULL,
                        const sf::Vector2f& dimensiune_adversar_=sf::Vector2f(0,0),
                        float hp_adversari=0,
                        bool viteza_variabila_=0);
    generator_adversari(const generator_adversari&)=default;
    friend void swap(generator_adversari&,generator_adversari&);
    generator_adversari& operator=(generator_adversari);
    ~generator_adversari()=default;
    void generare_adversari();
    void set_hp_adversari(float hp=0);
    void set_viteza_variabila(bool v_var=false);
};


class generator_adversari_factory
{
public:
    static void easy(generator_adversari*g=NULL){if(!g)return;
        g->set_hp_adversari(0);
        g->set_viteza_variabila(false);
    }
    static void medium(generator_adversari*g=NULL){if(!g)return;
        g->set_hp_adversari(200);
        g->set_viteza_variabila(false);
    }
    static void hard(generator_adversari*g=NULL){if(!g)return;
        g->set_hp_adversari(500);
        g->set_viteza_variabila(true);
    }
};

#endif // GENERATOR_ADVERSARI_H
