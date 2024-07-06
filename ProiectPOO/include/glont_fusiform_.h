#ifndef GLONT_FUSIFORM_H
#define GLONT_FUSIFORM_H
#include "glont.h"


class glont_fusiform : public glont
{
//    sf::Vector2f dimens_spatiu;
    sf::Color culoare;

public:
    glont_fusiform(sf::RenderWindow*,
                 const sf::Vector2f& dimens_spatiu_=sf::Vector2f(0,0),
                  const float& damage_=0,
                  const sf::Vector2f& pozitie_=sf::Vector2f(0,0),
                  const sf::Vector2f& viteza_init_=sf::Vector2f(0,-100),
                 const sf::Vector2f& dimens_=sf::Vector2f(10,10),
//                 const sf::Vector2f& vinit=sf::Vector2f(0,0),
                 const sf::Color& culoare_=sf::Color(0,0,255)
                 );

    void desenare();
    void miscare(const sf::Event& e,const sf::Clock& ceas);
};

#endif // GLONT_ROTUND_H
