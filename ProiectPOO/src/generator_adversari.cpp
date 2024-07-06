#include "generator_adversari.h"
#include "exceptii.h"

generator_adversari::generator_adversari(sf::RenderWindow*w,
                                        const sf::Vector2f&dimens_v,
                                        std::set<adversar*>* adversari_,
                                        nava* nava_mea_,
                                        const sf::Vector2f& viteza_adv,
                                        std::set<glont*>* gloante_,
                                        const sf::Vector2f& dimensiune_adversar_,
                                        float hp_adversari_,
                                        bool viteza_variabila_):fereastra(w),
                                                            dimensiune_virtuala_fereastra(dimens_v),
                                                            adversari(adversari_),
                                                            nava_mea(nava_mea_),
                                                            viteza_adversari(viteza_adv),
                                                            gloante(gloante_),
                                                            dimensiune_adversar(dimensiune_adversar_),
                                                            hp_adversari(hp_adversari_),
                                                            viteza_variabila(viteza_variabila_){
//                                                        if(!fereastra)throw(problema_imcarcare_fereastra("pointerul la sf::RenderWindow e null"));
                                                                adversar::init_dimensiune_virtuala_fereastra(dimensiune_virtuala_fereastra);
                                                            }
void swap(generator_adversari& g1,generator_adversari& g2)
{
    std::swap(g1.fereastra,g2.fereastra);
    std::swap(g1.dimensiune_virtuala_fereastra,g2.dimensiune_virtuala_fereastra);
    std::swap(g1.adversari,g2.adversari);
    std::swap(g1.nava_mea,g2.nava_mea);
    std::swap(g1.viteza_adversari,g2.viteza_adversari);
    std::swap(g1.gloante,g2.gloante);
    std::swap(g1.dimensiune_adversar,g2.dimensiune_adversar);
    std::swap(g1.culoare_adversar,g2.culoare_adversar);
    std::swap(g1.padding,g2.padding);
    std::swap(g1.viteza_variabila,g2.viteza_variabila);
    std::swap(g1.hp_adversari,g2.hp_adversari);
}
generator_adversari& generator_adversari::operator=(generator_adversari g)
{
    swap(*this,g);
    return *this;
}



//generator_adversari::~generator_adversari(){}

void generator_adversari::generare_adversari()
{
    if(ceas.getElapsedTime().asMilliseconds()>1200){
    int nr_adv_pe_rand=(int)((dimensiune_virtuala_fereastra.x-2.0*(nava_mea->get_dimensiune().x+2*padding))/
                                          (dimensiune_adversar.x+2*padding));

    for(int i=0;i<nr_adv_pe_rand;i++)
        if(std::rand()%2==0||std::rand()%3==0)
    {
        adversar* p= new adversar(fereastra,
                                  dimensiune_adversar,
                                  sf::Vector2f(nava_mea->get_dimensiune().x+padding+i*(dimensiune_adversar.x+padding),0),
                                  viteza_adversari+sf::Vector2f(0,(viteza_variabila==true ? rand()%200 : 0)),
                                  std::rand()%1000+hp_adversari,
                                  gloante,
                                  sf::Color(std::rand()%256,std::rand()%256,std::rand()%256)
                                  );
        p->get_img()->setOutlineColor(sf::Color(255,255,255));
        p->get_img()->setOutlineThickness(3);
        adversari->insert(p);
    }
    ceas.restart();
    }

}


void generator_adversari::set_hp_adversari(float hp){hp_adversari=hp;}
void generator_adversari::set_viteza_variabila(bool v_var){viteza_variabila=v_var;}
