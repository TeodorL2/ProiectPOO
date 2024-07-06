#ifndef ARMAMENT_BAZA_H
#define ARMAMENT_BAZA_H
#include "glont.h"
#include "glont_rotund.h"
#include "glont_linie.h"
#include "glont_fusiform.h"
#include "nava.h"
#include "armament_baza_netemplate.h"
#include <set>
#include <typeinfo>

template<class T>
class armament_baza;

template<class T>
void swap(armament_baza<T>&,armament_baza<T>&);

template <class T>
class armament_baza : public armament_baza_netemplate
{
protected:
    sf::RenderWindow* fereastra;
    static sf::Vector2f dimensiune_virtuala_fereastra;
    std::vector<glont*> gloante;
    sf::Vector2f* poz;//a navei
    const sf::Vector2f viteza_init;//a armei
    sf::Vector2f pozitie;//a armei
    sf::Vector2f dimens;//a navei
    sf::Vector2f dimensiune;//a armei
    sf::Shape* img_arma=NULL;
    int* nr_gloante=NULL;
    float damage;
    static float padding;
    bool activ=1;

    float perioada_tragare_milisec=100;
    sf::Clock ceas;
    static sf::Color culoare_gloante;

public:
    static void set_dimensiune_virtuala_fereastra(const sf::Vector2f&);
    static void set_culoare_gloante(const sf::Color& culoare=sf::Color(0,0,0));
//    void set_nr_gloante(int* x) override;
    armament_baza(sf::RenderWindow* fereastra_=NULL,
                  sf::Vector2f* pozitie_=NULL,
                  const sf::Vector2f& viteza_init_=sf::Vector2f(0,0),
                  const sf::Vector2f& dimensiune_nava=sf::Vector2f(0,0),
                  int* nr_gloante_=NULL,
                  const sf::Vector2f& dimens_arma=sf::Vector2f(0,0),
                  const sf::Vector2f& poz_arma=sf::Vector2f(0,0),
                  float damage_=0);
    armament_baza(const armament_baza&);
    virtual armament_baza<T>* clone()const override;
    friend void swap<T>(armament_baza&,armament_baza&);
    armament_baza<T>& operator=(armament_baza arma);
    virtual ~armament_baza();
    virtual void generare_gloante(std::set<glont*>&)override;
//    void set_perioada_tragere(const float& x)override;
//float get_perioada_tragare()const override;

void miscare(sf::Clock& cl)override;
//bool get_activ()const override;

void desenare_arma()override;
virtual void init_img_arma()override;

virtual sf::Shape* get_imagine()const override;

bool dezactivat() override;

//int get_nr_gloante()const override;

virtual void init_nr_gloante() override;

};




#include "../src/armament_baza.cpp"

#endif // ARMAMENT_BAZA_H
