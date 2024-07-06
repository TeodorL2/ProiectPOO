#ifndef GLONT_LINIE_H
#define GLONT_LINIE_H
#include "glont.h"


class glont_linie : public glont
{
    sf::Color culoare;

static sf::Vector2f dimensiune;

void creare_imagine();
public:
    static sf::Vector2f get_dimensiune();
    static void set_dimensiune(const sf::Vector2f& d);
    explicit glont_linie(sf::RenderWindow*,
                  const float& damage_=0,
                  const sf::Vector2f& pozitie_=sf::Vector2f(0,0),
                  const sf::Vector2f& viteza_init_=sf::Vector2f(0,-100),
                 const sf::Color& culoare_=sf::Color(255,255,255)
                 );
    glont_linie(const glont_linie&);
    friend void swap(glont_linie&,glont_linie&);
    glont_linie& operator=(glont_linie g);
    glont* clone()const override;
    void desenare() override;
    void miscare(const sf::Clock& ceas) override;
};

#endif // GLONT_LINIE_H
