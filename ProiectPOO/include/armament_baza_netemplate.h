#ifndef ARMAMENT_BAZA_NETEMPLATE_H
#define ARMAMENT_BAZA_NETEMPLATE_H

#include <set>
#include "glont.h"

class armament_baza_netemplate
{
public:
    virtual ~armament_baza_netemplate()=0;
    virtual void generare_gloante(std::set<glont*>&)=0;
//    virtual void set_perioada_tragere(const float& x)=0;
//virtual float get_perioada_tragare()const =0;

virtual void miscare(sf::Clock& cl)=0;
//virtual bool get_activ()const=0;

virtual void desenare_arma()=0;
virtual void init_img_arma()=0;

virtual sf::Shape* get_imagine()const=0;

virtual bool dezactivat()=0;

//virtual int get_nr_gloante()const=0;

virtual void init_nr_gloante()=0;

//virtual void set_nr_gloante(int* x);

virtual armament_baza_netemplate* clone()const=0;

};

#endif // ARMAMENT_BAZA_NETEMPLATE_H
