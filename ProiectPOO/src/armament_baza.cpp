#ifndef ARMAMENT_BAZA_CPP
#define ARMAMENT_BAZA_CPP
#include <set>
#include <iostream>
#include "exceptii.h"
#include "armament_baza.h"


template<class T>
sf::Color armament_baza<T>::culoare_gloante=sf::Color(0,0,0);

template<class T>
void armament_baza<T>::set_culoare_gloante(const sf::Color& culoare)
{
    culoare_gloante=culoare;
}

template<class T>
sf::Vector2f armament_baza<T>::dimensiune_virtuala_fereastra=sf::Vector2f(0,0);

template<class T>
float armament_baza<T>::padding=2;

//template<class T>
//void armament_baza<T>::set_nr_gloante(int* x){nr_gloante=x;}

template<class T>
void armament_baza<T>::set_dimensiune_virtuala_fereastra(const sf::Vector2f& d){armament_baza<T>::dimensiune_virtuala_fereastra=d;}

template<class T>
armament_baza<T>::
    armament_baza(sf::RenderWindow* w,
                  sf::Vector2f* pozitie_,
                  const sf::Vector2f& viteza_init_,
                  const sf::Vector2f& dimensiune_,
                  int* nr_gloante_,
                  const sf::Vector2f&dimens_arma_,
                  const sf::Vector2f& poz_arma_,
                  float damage_):fereastra(w),
                                        poz(pozitie_),
                                        viteza_init(viteza_init_),
                                        pozitie(poz_arma_),
                                        dimens(dimensiune_),
                                        dimensiune(dimens_arma_),
                                        nr_gloante(nr_gloante_),
                                        damage(damage_){
//if(!fereastra)throw(problema_imcarcare_fereastra("pointerul la sf::RenderWindow e null"));
                                                    }
template<class T>
sf::Shape* armament_baza<T>::get_imagine()const{

return img_arma;}

//template<class T>
//int armament_baza<T>::get_nr_gloante()const{return *nr_gloante;}

template<class T>
armament_baza<T>::armament_baza(const armament_baza<T>& arma):
    fereastra(arma.fereastra),
    poz(arma.poz),
    viteza_init(arma.viteza_init),//a armei
    pozitie(arma.pozitie),//a armei
    dimens(arma.dimens),//a navei
    dimensiune(arma.dimensiune),//a armei
    nr_gloante(arma.nr_gloante),
    damage(arma.damage),
    activ(arma.activ),
    perioada_tragare_milisec(arma.perioada_tragare_milisec)
    {
        for(auto i:arma.gloante)
        {
            glont* p=i->clone();
            gloante.push_back(p);
        }

        if(sf::CircleShape*p=dynamic_cast<sf::CircleShape*>(arma.img_arma))
            {img_arma=new sf::CircleShape(p->getRadius());
            img_arma->setFillColor(p->getFillColor());
            img_arma->setPosition(p->getPosition());
            }
        else
            if(sf::RectangleShape*q=dynamic_cast<sf::RectangleShape*>(arma.img_arma))
                {
                    img_arma=new sf::RectangleShape(q->getSize());
                    img_arma->setFillColor(q->getFillColor());
                    img_arma->setPosition(q->getPosition());
                }
            else
                throw(forma_necunoscuta("nu a putut fi recunoscuta forma"));

    }

template<class T>
void swap(armament_baza<T>& a1,armament_baza<T>& a2)
{
    std::swap(a1.fereastra,a2.fereastra);
    std::swap(a1.viteza_init,a2.viteza_init);//a armei
    std::swap(a1.pozitie,a2.pozitie);//a armei
    std::swap(a1.dimens,a2.arma.dimens);//a navei
    std::swap(a1.dimensiune,a2.dimensiune);//a armei
    std::swap(a1.nr_gloante,a2.arma.nr_gloante);
    std::swap(a1.activ,a2.activ);
    std::swap(a1.perioada_tragare_milisec,a2.perioada_tragare_milisec);
    std::swap(a1.damage,a2.damage);
    std::swap(a1.gloante,a2.gloante);
    std::swap(a1.poz,a2.poz);
    std::swap(a1.img_arma,a2.img_arma);

}

template<class T>
armament_baza<T>& armament_baza<T>::operator=(armament_baza<T> a)
{
    swap(*this,a);
    return *this;
}

template<class T>
armament_baza<T>::~armament_baza(){
delete img_arma;
gloante.clear();
}

template<class T>
bool armament_baza<T>::dezactivat()
{
    if(pozitie.x<0 || pozitie.y<0 || pozitie.x>dimensiune_virtuala_fereastra.x || pozitie.y>dimensiune_virtuala_fereastra.y)
        {activ=false;return false;}
    return true;
}



template<class T> /// utilizare cu sens a argumentului template primit (**)
void armament_baza<T>::generare_gloante(std::set<glont*>& g)
{
    if(ceas.getElapsedTime().asMilliseconds()<perioada_tragare_milisec)return;
    else
        ceas.restart();

    gloante.clear();
 sf::Vector2f offset=sf::Vector2f((dimens.x-(T::get_dimensiune().x+2*armament_baza<T>::padding)*(*nr_gloante))/2+poz->x,poz->y-T::get_dimensiune().y);
 glont* p=NULL;
 for(int i=0;i<*nr_gloante;i++)
 {p = new T(fereastra,damage,  /// (**) aici
        offset+sf::Vector2f((T::get_dimensiune().x+2*armament_baza<T>::padding)*(float)i+armament_baza<T>::padding,0),
            sf::Vector2f(0,-800),armament_baza<T>::culoare_gloante);
 gloante.push_back(p);
 }

 try{
    for(auto i=0ull;i<gloante.size();i++)
        {g.insert(gloante[i]);
        }
    }
    catch(std::runtime_error&){throw 1;}
}

//template <class T>
//void armament_baza<T>::set_perioada_tragere(const float& x){perioada_tragare_milisec=x;}

//template <class T>
//float armament_baza<T>::get_perioada_tragare()const {return perioada_tragare_milisec;}


template<class T>
void armament_baza<T>::miscare(sf::Clock& cl)
{
    sf::Time timp=cl.getElapsedTime();
    pozitie+=viteza_init* timp.asSeconds();


    if(pozitie.x<0)
        activ=false;
    if(pozitie.y<0)
        activ=false;
    sf::Vector2f d_fereastra=dimensiune_virtuala_fereastra;

    if(pozitie.x+dimensiune.x>d_fereastra.x)
        activ=false;
    if(pozitie.y+dimensiune.y>d_fereastra.y)
        activ=false;
}

//template<class T>
//bool armament_baza<T>::get_activ()const{return activ;}

template<class T>
void armament_baza<T>::init_img_arma()
{
    img_arma->setPosition(pozitie);
}

template<class T>
void armament_baza<T>::desenare_arma(){
    init_img_arma();
    fereastra->draw(*img_arma);
}

template<class T>
void armament_baza<T>::init_nr_gloante(){}

template<class T>
armament_baza<T>* armament_baza<T>::clone()const{return new armament_baza(*this);}

#endif // ARMAMENT_BAZA_H
