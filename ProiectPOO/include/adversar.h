#ifndef ADVERSAR_H
#define ADVERSAR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <set>
#include "glont.h"

class adversar
{
protected:
    sf::RenderWindow* fereastra=NULL;
    static sf::Vector2f dimensiune_virtuala_fereastra;
    sf::Vector2f dimensiune;
    sf::Vector2f pozitie;
    sf::Vector2f viteza;
    float hp;
    std::set<glont*>* gloante;
    sf::Shape* img_adversar;
    sf::Color culoare;

    void creare_imagine();
public:
    static void init_dimensiune_virtuala_fereastra(const sf::Vector2f&);
    adversar(sf::RenderWindow*w=NULL,
             const sf::Vector2f& dimens=sf::Vector2f(0,0),
             const sf::Vector2f& poz=sf::Vector2f(0,0),
             const sf::Vector2f& vit=sf::Vector2f(0,0),
             float hp_=0,
             std::set<glont*>* gloante_=NULL,
             const sf::Color& culoare_=sf::Color(255, 153, 102));
    adversar(const adversar&);
    friend void swap(adversar&,adversar&);
    adversar& operator=(adversar);
    virtual ~adversar();
    void miscare(sf::Clock&);
    void contact_gloante();
    sf::Shape* get_img()const;
    sf::Vector2f get_dimensiune()const;
    float get_hp()const;
    void desenare()const;
sf::Shape* get_imagine()const;

};

#endif // ADVERSAR_H
