#ifndef GLONT_H
#define GLONT_H
#include <SFML/Graphics.hpp>
#include <iostream>

class glont
{
protected:
    sf::RenderWindow* fereastra;
    static float damage;
    sf::Vector2f pozitie;
    const sf::Vector2f viteza_init;

    sf::Vector2f viteza;
    std::vector<sf::Shape*> img_glont={};
    bool activ=1;
    static sf::Vector2f dimensiune_virtuala_fereastra;

public:
    static void init_clasa(const sf::Vector2f& dimens=sf::Vector2f(0,0));
    glont(sf::RenderWindow*,
          const float& d=0,
          const sf::Vector2f& poz=sf::Vector2f(0,0),
          const sf::Vector2f& v_init=sf::Vector2f(0,0),
          const sf::Vector2f& vit=sf::Vector2f(100,100));
    glont(const glont&);
    friend void swap(glont& g1, glont& g2);
    glont& operator=(const glont& g);


    virtual ~glont();
    virtual glont* clone()const=0;
    virtual void desenare()=0;
    virtual void miscare(const sf::Clock&)=0;
//    virtual void set_damage(float d);
    virtual float get_damage() const ;
    virtual void set_dezactivat();
    virtual const std::vector<sf::Shape*>* get_imagine()const;
    bool dezactivat();
};


#endif // GLONT_H
