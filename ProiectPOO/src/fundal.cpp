#include "fundal.h"
#include "exceptii.h"

fundal::fundal(sf::RenderWindow* w, const sf::Vector2f& d,const sf::Color& culoare):fereastra(w),dreptunghi_fundal(d)
{
    dreptunghi_fundal.setFillColor(culoare);
}
//sf::RectangleShape fundal::get_fundal() const {return dreptunghi_fundal;}

    void fundal::desenare_fundal()
    {
        fereastra->draw(dreptunghi_fundal);
    }

void swap(fundal& f1,fundal& f2)
{
    std::swap(f1.dreptunghi_fundal,f2.dreptunghi_fundal);
    std::swap(f1.fereastra,f2.fereastra);
}

fundal& fundal::operator=(fundal f){
swap(*this,f);
return *this;
}
