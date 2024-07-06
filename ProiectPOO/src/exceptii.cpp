#include "exceptii.h"

problema_imcarcare_fereastra::problema_imcarcare_fereastra(const std::string& mesaj):runtime_error(mesaj){}

forma_necunoscuta::forma_necunoscuta(const std::string& mesaj):runtime_error(mesaj){}
