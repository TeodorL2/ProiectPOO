#ifndef NAVA_H
#define NAVA_H
#include <SFML/Graphics.hpp>
#include <iostream>


class nava
{
    sf::RenderWindow* fereastra;
    sf::Vector2f pozitie=sf::Vector2f(0,0);
    sf::Vector2f dimensiune;
    std::vector<sf::RectangleShape> piese_nava;
    sf::Color culoare;
    sf::Vector2f dimensiuni_virtuale_fereastra;
    int focus=0;
protected:
    void init_piese();
public:
    bool intersecteaza(const sf::Shape*);
    int get_focus() const;
    void set_focus();
    nava(sf::RenderWindow* f=NULL,
         const sf::Vector2f& poz = sf::Vector2f(0,0),
         const sf::Vector2f& dimens = sf::Vector2f(0,0),
         const unsigned int& nrp=0,
         const sf::Color& c=sf::Color(0,0,0),
         const sf::Vector2f& d_v=sf::Vector2f(0,0));
    nava(const nava& n);
    friend void swap(nava&,nava&);
    nava& operator=(nava);


    virtual ~nava()=default;

    sf::Vector2f* get_pozitie_pointer() const;

    void desenare_nava();
//    std::vector<sf::RectangleShape> get_img_nava() const;
    void set_viteza(const sf::Vector2f& v);
    const sf::Vector2f& get_viteza() const;
    void miscare(const float& timp);
    void set_viteza_x(const float& x=1);
    void set_viteza_y(const float& y=1);
    void resetare_viteza();
    sf::Vector2f get_dimensiune() const;
    void set_dimensiune(const sf::Vector2f&);
//    sf::Vector2f get_pozitie() const;
//    void set_pozitie(const sf::Vector2f&);
//
//    void set_pozitie_x(const float&);
//    void set_pozitie_y(const float&);
    void miscare2(const sf::Event&);
};

#endif // NAVA_H
