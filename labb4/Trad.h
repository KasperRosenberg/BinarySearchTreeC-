//Kasper Rosenberg - karo5568
//  Trad.h
//  labb4_tree

#ifndef TRAD_H
#define TRAD_H
#include <iostream>

template <typename T>
class Trad {
public: 
    Trad() : rot(0) {};                    // default konstruktor
    Trad(T d) { rot = new Nod(d); };
    Trad(const Trad& t) { kopiera(t); };   // kopieringskonstruktor
    ~Trad() { delete rot; };

    bool tomt() const { return !rot; };
    T& varde() const
    {
        koll();
        return rot->data;
    };
    Trad& v_barn() const
    {
        koll();
        return *rot->vanster;
    };
    Trad& h_barn() const
    {
        koll();
        return *rot->hoger;
    };

    Trad& operator= (const Trad& t)
    {
        //std::cout << "*** Trad::operator=\n";
        if (rot != t.rot)
        {
            delete rot;
            kopiera(t);
        }
        return *this;
    }

    bool operator== (const Trad& t) const
    {
        //std::cout << "*** Trad::operator==\n";
        return (tomt() && t.tomt()) ||
            (!tomt() && !t.tomt() && varde() == t.varde() &&
                v_barn() == t.v_barn() && h_barn() == t.h_barn());
    }

    void skriv_ut() const
    {
        // traversera igenom trädet rekursivt enligt principen "in-order"
        if (!tomt())
        {
            v_barn().skriv_ut();
            std::cout << varde() << ' ';
            h_barn().skriv_ut();
        }
    }
    bool sok(const T& i) {
        //Sök igenom trädet efter parametern som skickas med genom rekusiv traversering
        if (!tomt()) {
            if (rot->data == i) {
                return true;
            }
            else if (i < rot->data) {
                return v_barn().sok(i);
            }
            else if (i > rot->data) {
                return  h_barn().sok(i);
            }
        }
        return false;
    }

    void satt_in(const T& i) {
        //Leta upp rätt plats att stoppa in värdet som skickas med genom rekursiv traversering
        if (!tomt()) {
            if (i < rot->data) {
                if (v_barn().tomt()) {
                    v_barn() = Trad(i);
                }
                v_barn().satt_in(i);
            }
            else if (i > rot->data) {
                if (h_barn().tomt()) {
                    h_barn() = Trad(i);
                }
                h_barn().satt_in(i);
            }
        }
        else {
            rot = new Nod(i);
        }
    }

private:
    class Nod {
        friend class Trad;
        T data;
        Trad* vanster, * hoger;
        Nod(T d) : data(d), vanster(new Trad), hoger(new Trad) {};
        ~Nod()
        {
            delete vanster;
            delete hoger;
        };
    }; // end class Nod

    Nod* rot;
    void koll() const
    {
        if (tomt()) 
            throw std::range_error("Trad");
    }
    void kopiera(const Trad& t)
    {
        //std::cout << "*** Trad::kopiera\n";
        if (t.tomt())
            rot = 0;
        else
        {
            rot = new Nod(t.varde());
            v_barn().kopiera(t.v_barn());
            h_barn().kopiera(t.h_barn());
        }
    }
};

#endif /* Trad_h */
