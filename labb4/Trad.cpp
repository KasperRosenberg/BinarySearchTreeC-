//Kasper Rosenberg - karo5568
//  Trad.cpp
//  labb4_tree

//#include <iostream>
//#include "Trad.h"

//void kopiera(const Trad& t)
//{
//    //std::cout << "*** Trad::kopiera\n";
//    if (t.tomt())
//        rot = 0;
//    else
//    {
//        rot = new Nod<T>(t.varde());
//        v_barn().kopiera(t.v_barn());
//        h_barn().kopiera(t.h_barn());
//    }
//}
    
//template <typename T>
//Trad<T>& Trad<T>::operator= (const Trad& t)
//{
//    //std::cout << "*** Trad::operator=\n";
//    if (rot != t.rot)
//    {
//        delete rot;
//        kopiera(t);
//    }
//    return *this;
//}
//template <typename T>
//bool Trad<T>::operator== (const Trad& t) const
//{
//    //std::cout << "*** Trad::operator==\n";
//    return (tomt() && t.tomt()) ||
//        (!tomt() && !t.tomt() && varde() == t.varde() &&
//            v_barn() == t.v_barn() && h_barn() == t.h_barn());
//}

//template <typename T>
//void Trad<T>::skriv_ut() const
//{
//    // traversera igenom trädet rekursivt enligt principen "in-order"
//    if (!tomt())
//    {
//        v_barn().skriv_ut();
//        std::cout << varde() << ' ';
//        h_barn().skriv_ut();
//    }
//}



