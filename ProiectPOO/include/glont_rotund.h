#ifndef GLONT_ROTUND_H
#define GLONT_ROTUND_H
#include "glont.h"


class glont_rotund : public glont
{

    sf::Color culoare;
    static sf::Vector2f dimensiune;

    void creare_imagine();
public:
    static sf::Vector2f get_dimensiune();
    static void set_dimensiune(const sf::Vector2f& d);
    explicit glont_rotund(sf::RenderWindow*,
                  const float& damage_=0,
                  const sf::Vector2f& pozitie_=sf::Vector2f(0,0),
                  const sf::Vector2f& viteza_init_=sf::Vector2f(0,-100),
                 const sf::Color& culoare_=sf::Color(0,0,255)
                 );
    friend void swap(glont_rotund&,glont_rotund&);
    glont_rotund& operator=(glont_rotund g);
    glont_rotund(const glont_rotund& g);
    glont* clone()const override;
    void desenare() override;
    void miscare(const sf::Clock& ceas) override;
};

#endif // GLONT_ROTUND_H
