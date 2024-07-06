#include "adversar.h"
#include "exceptii.h"

sf::Vector2f adversar::dimensiune_virtuala_fereastra=sf::Vector2f(0,0);

void adversar::init_dimensiune_virtuala_fereastra(const sf::Vector2f& dimens_v){adversar::dimensiune_virtuala_fereastra=dimens_v;}

adversar::~adversar()
{
    delete img_adversar;
}

void adversar::creare_imagine()
{
    img_adversar = new sf::RectangleShape(dimensiune);
                                        img_adversar->setFillColor(culoare);
}

adversar::adversar(sf::RenderWindow* w,
             const sf::Vector2f& dimens,
             const sf::Vector2f& poz,
             const sf::Vector2f& vit,
             float hp_,
             std::set<glont*>* gloante_,
             const sf::Color& culoare_):fereastra(w),
                                        dimensiune(dimens),
                                        pozitie(poz),
                                        viteza(vit),
                                        hp(hp_),
                                        gloante(gloante_),
                                        culoare(culoare_){
//if(!fereastra)throw(problema_imcarcare_fereastra("pointerul la sf::RenderWindow e null"));
                                        creare_imagine();
                                        }
adversar::adversar(const adversar& a):
    fereastra(a.fereastra),
    dimensiune(a.dimensiune),
    pozitie(a.pozitie),
    viteza(a.viteza),
    hp(a.hp),
    gloante(a.gloante),
    culoare(a.culoare)
    {
            creare_imagine();
    }

void swap(adversar& a1,adversar& a2)
{
    std::swap(a1.fereastra,a2.fereastra);
    std::swap(a1.dimensiune,a2.dimensiune);
    std::swap(a1.pozitie,a2.pozitie);
    std::swap(a1.viteza,a2.viteza);
    std::swap(a1.hp,a2.hp);
    std::swap(a1.gloante,a2.gloante);
    std::swap(a1.culoare,a2.culoare);
    std::swap(a1.img_adversar,a2.img_adversar);
}

adversar& adversar::operator=(adversar a)
{
    std::swap(*this,a);
    return *this;
}

void adversar::miscare(sf::Clock& ceas)
{
    sf::Time timp=ceas.getElapsedTime();
    pozitie+=viteza* timp.asSeconds();

    if(pozitie.x<0)
        hp=0;
    if(pozitie.y<0)
        hp=0;
    sf::Vector2f d_fereastra=dimensiune_virtuala_fereastra;

    if(pozitie.x>d_fereastra.x)
        hp=0;
    if(pozitie.y>d_fereastra.y)
        hp=0;

}

void adversar::contact_gloante()
{
    for(auto i=gloante->begin();i!=gloante->end();i++)
    {
        for(auto j:*((*i)->get_imagine()))
        if(img_adversar->getGlobalBounds().intersects(j->getGlobalBounds()))
        {hp-=(*i)->get_damage();(*i)->set_dezactivat();}
    }
}

sf::Vector2f adversar::get_dimensiune()const{return dimensiune;}

sf::Shape* adversar::get_img()const{return img_adversar;}

float adversar::get_hp()const{return hp;}

void adversar::desenare()const{
    img_adversar->setPosition(pozitie);
    fereastra->draw(*img_adversar);
}

sf::Shape* adversar::get_imagine()const{return img_adversar;}
