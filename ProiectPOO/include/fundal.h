#ifndef FUNDAL_H
#define FUNDAL_H

#include <SFML/Graphics.hpp>

class fundal
{
    sf::RenderWindow* fereastra;
    sf::RectangleShape dreptunghi_fundal;
public:
    fundal()=default;
    fundal(sf::RenderWindow*, const sf::Vector2f& dimens,const sf::Color& culoare=sf::Color(0,0,0));
    friend void swap(fundal&,fundal&);
    fundal& operator=(fundal f);
    fundal(const fundal& f)=default;
    virtual ~fundal()=default;
//    sf::RectangleShape get_fundal() const;
    void desenare_fundal();

};

#endif // FUNDAL_H
