#ifndef ARMA_PLUS_UN_GLONT_CPP
#define ARMA_PLUS_UN_GLONT_CPP


#include "arma_plus_un_glont.h"

template<class T>
void arma_plus_un_glont<T>::creare_imagine()
{
    armament_baza<T>::img_arma= new sf::CircleShape(std::min(armament_baza<T>::dimensiune.x,armament_baza<T>::dimensiune.y));
                    armament_baza<T>::img_arma->setFillColor(sf::Color(0,255,0));
}

template<class T>
arma_plus_un_glont<T>::
    arma_plus_un_glont(sf::RenderWindow* w,
                  sf::Vector2f* pozitie_,
                  const sf::Vector2f& viteza_init_,
                  const sf::Vector2f& dimensiune_,
                  int* nr_gloante_,
                  const sf::Vector2f& dimens_arma_,
                  const sf::Vector2f& poz_arma_,
                  float damage):
                                    armament_baza<T>(w,pozitie_,viteza_init_,dimensiune_,nr_gloante_,dimens_arma_,poz_arma_,damage){

                    creare_imagine();

                                             }

template<class T>
arma_plus_un_glont<T>::arma_plus_un_glont(const arma_plus_un_glont<T>& a):
    armament_baza<T>(a)
    {
        creare_imagine();
    }

template<class T>
void swap(arma_plus_un_glont<T>& a1,arma_plus_un_glont<T>& a2)
{
    swap(static_cast<armament_baza<T>&>(a1),static_cast<armament_baza<T>&>(a2));
}

template<class T>
arma_plus_un_glont<T>& arma_plus_un_glont<T>::operator=(arma_plus_un_glont a)
{
    swap(*this,a);
    return *this;
}

template<class T>
void arma_plus_un_glont<T>::init_nr_gloante(){
if(*armament_baza<T>::nr_gloante<5)
    ++(*armament_baza<T>::nr_gloante);
}

template<class T>
void arma_plus_un_glont<T>::init_img_arma()
{
    armament_baza<T>::img_arma->setPosition(armament_baza<T>::pozitie);
}

template<class T>
armament_baza<T>* arma_plus_un_glont<T>::clone()const{return new arma_plus_un_glont<T>(*this);}


#endif // ARMA_PLUS_UN_GLONT_CPP
