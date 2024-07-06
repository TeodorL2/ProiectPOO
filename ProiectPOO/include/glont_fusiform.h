#ifndef GLONT_FUSIFORM_H
#define GLONT_FUSIFORM_H
#include "glont.h"


class glont_fusiform : public glont
{
    sf::Color culoare;
    static sf::Vector2f dimensiune;

    void creare_imagine();
public:
    static sf::Vector2f get_dimensiune();
    static void set_dimensiune(const sf::Vector2f& d);
    explicit glont_fusiform(sf::RenderWindow*,
                  const float& damage_=0,
                  const sf::Vector2f& pozitie_=sf::Vector2f(0,0),
                  const sf::Vector2f& viteza_init_=sf::Vector2f(0,-300),
                 const sf::Color& culoare_=sf::Color(0,0,255)
                 );
    glont_fusiform(const glont_fusiform&);
    friend void swap(glont_fusiform&,glont_fusiform&);
    glont_fusiform& operator=(glont_fusiform);
    glont* clone()const override;

    void desenare() override;
    void miscare(const sf::Clock& ceas) override;
};

#endif // GLONT_ROTUND_H
