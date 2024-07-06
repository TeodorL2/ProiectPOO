#ifndef ARMA_MINUS_UN_GLONT_H
#define ARMA_MINUS_UN_GLONT_H

#include "armament_baza.h"

template<class T>
class arma_minus_un_glont;

template<class T>
void swap(arma_minus_un_glont<T>&,arma_minus_un_glont<T>&);

template<class T>
class arma_minus_un_glont : public armament_baza<T>
{
public:
    arma_minus_un_glont(sf::RenderWindow* fereastra_=NULL,
                  sf::Vector2f* pozitie_=NULL,
                  const sf::Vector2f& viteza_init_=sf::Vector2f(0,0),
                  const sf::Vector2f& dimensiune=sf::Vector2f(0,0),
                  int* nr_gloante_=NULL,
                  const sf::Vector2f& dimens_arma=sf::Vector2f(0,0),
                  const sf::Vector2f& poz_arma_=sf::Vector2f(0,0),
                  float damage=0);
    arma_minus_un_glont(const arma_minus_un_glont&);
    friend void swap<T>(arma_minus_un_glont&,arma_minus_un_glont&);
    arma_minus_un_glont& operator=(arma_minus_un_glont);
    armament_baza<T>* clone() const override;
    void init_img_arma() override;
    void init_nr_gloante() override;
    void creare_imagine();
};

#include "../src/arma_minus_un_glont.cpp"

#endif // ARMA_PLUS_UN_GLONT_H
