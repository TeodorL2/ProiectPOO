#include "nava.h"
#include "exceptii.h"

nava::nava(sf::RenderWindow* f,const sf::Vector2f& poz,const sf::Vector2f& dimens,
            const unsigned int& nr_piese_,const sf::Color& c,const  sf::Vector2f& d_v):
    fereastra(f),pozitie(poz),dimensiune(dimens),culoare(c),dimensiuni_virtuale_fereastra(d_v)
{
//    if(!fereastra)throw(problema_imcarcare_fereastra("pointerul la sf::RenderWindow e null"));
sf::RectangleShape piesa_nava_(dimens/(float)3.0);
piesa_nava_.setFillColor(c);
for(auto i=0ull;i<nr_piese_;i++)
    piese_nava.push_back(piesa_nava_);
}

nava::nava(const nava& n):fereastra(n.fereastra),
pozitie(n.pozitie),
dimensiune(n.dimensiune),
piese_nava(n.piese_nava),
culoare(n.culoare),
dimensiuni_virtuale_fereastra(n.dimensiuni_virtuale_fereastra){}

void swap(nava& n1,nava& n2)
{
    std::swap(n1.fereastra,n2.fereastra);
    std::swap(n1.pozitie,n2.pozitie);
    std::swap(n1.dimensiune,n2.dimensiune);
    std::swap(n1.piese_nava,n2.piese_nava);
    std::swap(n1.culoare,n2.culoare);
    std::swap(n1.dimensiuni_virtuale_fereastra,n2.dimensiuni_virtuale_fereastra);
}

    nava& nava::operator=(nava n)
    {
        swap(*this,n);
        return *this;
    }

void nava::init_piese()
{
    piese_nava[0].setPosition(pozitie.x+dimensiune.x/3,pozitie.y);
for(auto i=1ull;i<4;i++)
    piese_nava[i].setPosition(pozitie.x+(i-1)*dimensiune.x/3,pozitie.y+dimensiune.y/3);
piese_nava[4].setPosition(pozitie.x,pozitie.y+2*dimensiune.y/3);
piese_nava[5].setPosition(pozitie.x+dimensiune.x*2/3.0,pozitie.y+2*dimensiune.y/3);
}

void nava::desenare_nava()
{
    init_piese();
    for(auto i=0ull;i<piese_nava.size();i++)
        fereastra->draw(piese_nava[i]);
}

//std::vector<sf::RectangleShape> nava::get_img_nava() const {return piese_nava;}


sf::Vector2f nava::get_dimensiune() const {return dimensiune;}
    void nava::set_dimensiune(const sf::Vector2f& d) {dimensiune=d;}

//sf::Vector2f nava::get_pozitie() const {return pozitie;}
//    void nava::set_pozitie(const sf::Vector2f&p){pozitie=p;}
//
//
//void nava::set_pozitie_x(const float& x){pozitie.x=x;}
//void nava::set_pozitie_y(const float& y){pozitie.y=y;}

void nava::miscare2(const sf::Event& e)
{

if(e.type==sf::Event::MouseMoved && focus==1)
    {
    float raport_x=dimensiuni_virtuale_fereastra.x/fereastra->getSize().x;
    float raport_y=dimensiuni_virtuale_fereastra.y/fereastra->getSize().y;
    pozitie=sf::Vector2f(e.mouseMove.x*raport_x,e.mouseMove.y*raport_y);
    }

    if(pozitie.x<0)
        pozitie.x=0;
    if(pozitie.y<0)
        pozitie.y=0;
    sf::Vector2f d_fereastra=dimensiuni_virtuale_fereastra;


    if(pozitie.x+dimensiune.x>d_fereastra.x)
        pozitie.x=d_fereastra.x-dimensiune.x;
    if(pozitie.y+dimensiune.y>d_fereastra.y)
        pozitie.y=d_fereastra.y-dimensiune.y;

    init_piese();

}

sf::Vector2f* nava::get_pozitie_pointer() const {return (sf::Vector2f*)&pozitie;}

int nava::get_focus() const {return focus;}
    void nava::set_focus(){focus^=1;}

bool nava::intersecteaza(const sf::Shape* x)
{
    for(auto i:piese_nava)
    {
        if(x->getGlobalBounds().intersects(i.getGlobalBounds()))
            return true;
    }
    return false;
}
