#include "Biblioteca.hpp"

int main() {
  Biblioteca biblioteca = {
    {
      {
        "9780452284234",
        "1984",
        {"George Orwell"},
        "Plume"
      },
      {
        "9785521005543",
        "Crime and Punisment",
        {"Fyodor Dostoevsky"},
        "Palmira"
      },
      {
        "9780141439976",
        "The Time Machine",
        {"H.G. Wells"},
        "Penguin Books"
      },
      {
        "9788845223181",
        "L'isola del giorno prima",
        {"Umberto Eco"},
        "Bompiani"
      },
      {
        "9780375704024",
        "Norwegian Wood",
        {"Haruki Murakami"},
        "Vintage Books"
      }
    },
    {
      {1, "Linus Torvalds"},
      {2, "Dennis Ritchie"},
      {3, "Richard Stallman"},
      {4, "Bjarne Stroustrup"},
      {5, "Bram Moolenar"}
    }
  };

  unsigned azione;
  do {
    cout << "Scegli azione:\n"
            "\t0 - Esci\n"
            "\t1 - Inserisci Libro\n"
            "\t2 - Rimuovi Libro\n"
            "\t3 - Inserisci Cliente\n"
            "\t4 - Rimuovi Cliente\n"
            "\t5 - Aggiungi prestito\n"
            "\t6 - Riconsegna\n"
            "\t7 - Visualizza libri in prestito\n"
            "\t8 - Visualizza Clienti con un libro in prestito\n"
            "Azione [0-8]: ";
    cin >> azione;
    switch (azione) {
    case 0:
      cout << "Buona giornata!" << endl;
      return 0;
    case 1: {
      string isbn = "", titolo = "", autore = "", casaEditrice = "";
      vector<string> autori = {};

      cout << "\tISBN: ";
      cin >> isbn;

      // L'ultima cin ha lasciato '\n' sullo stream. Se non la si ignora
      // getline() terminerà subito.
      cin.ignore();

      cout << "\tTitolo: ";
      getline(cin, titolo);

      cout << "\tInserisci una lista di autori, termina con 0.\n";
      while (autore != "0") {
        cout << "\t\tAutore: ";
        getline(cin, autore);
        autori.push_back(autore);
      }

      cout << "\tCasa Editrice: ";
      getline(cin, casaEditrice);

      // Usa implicitamente il costruttore con parametri di Libro
      biblioteca.aggiungiLibro({isbn, titolo, autori, casaEditrice});
      cout << "\tLibro aggiunto!" << endl;
      break;
    }
    case 2: {
      vector<Libro>::size_type last = biblioteca.stampaScaffale(), index = 0;
      cout << "\tLibro da Rimuovere [1-" << last << "]: ";
      cin >> index;
      if (index < 1 || index > last) {
        cout << "\tOperazione annullata." << endl;
        break;
      }
      biblioteca.rimuoviLibro(index - 1);
      cout << "\tLibro rimosso!" << endl;
      break;
    }
    case 3: {
      unsigned id = 0;
      string nome = "";

      cout << "\tID: ";
      cin >> id;

      cin.ignore();
      cout << "\tNome: ";
      getline(cin, nome);

      biblioteca.aggiungiCliente({id, nome});
      cout << "\tCliente aggiunto!" << endl;
      break;
    }
    case 4: {
      vector<Cliente>::size_type last = biblioteca.stampaTesserati(), index = 0;
      cout << "\tCliente da rimuovere [1-" << last << "]: ";
      cin >> index;
      if (index < 1 || index > last) {
        cout << "\tOperazione annullata." << endl;
        break;
      }
      biblioteca.rimuoviCliente(index - 1);
      cout << "\tCliente rimosso!" << endl;
      break;
    }
    case 5: {
      vector<Libro> disponibili = biblioteca.prestabili();
      if (disponibili.empty()) {
        cout << "\tNon ci sono libri disponibili." << endl;
        break;
      }

      vector<Libro>::size_type iLibro = 0;
      cout << "\tLibro da prestare [1-" << disponibili.size() << "]: ";
      cin >> iLibro;

      if (iLibro < 1 || iLibro > disponibili.size()) {
        cout << "\tOperazione annullata." << endl;
        break;
      }

      vector<Cliente> eleggibili = biblioteca.clientiEleggibili();
      if (eleggibili.empty()) {
        cout << "\tNon ci sono clienti eleggibili." << endl;
        break;
      }
      vector<Cliente>::size_type iCliente = 0;
      cout << "\tCliente a cui perstarlo [1-" << eleggibili.size() << "]: ";
      cin >> iCliente;

      if (iCliente < 1 || iCliente > eleggibili.size()) {
        cout << "\tOperazione annullata." << endl;
        break;
      }

      biblioteca.aggiungiPresito(disponibili[iLibro - 1],
                                 eleggibili[iCliente - 1]);
      cout << "\tPrestito aggiunto nel registro dei prestiti." << endl;
      break;
    }
    case 6: {
      vector<Libro> opzioni = biblioteca.prestati();

      if (opzioni.empty()) {
        cout << "\tNon ci sono libri da riconsegnare." << endl;
        break;
      }

      cout << "\tLibro da riconsegnare [1-" << opzioni.size() << "]: ";
      vector<Libro>::size_type i;
      cin >> i;

      if (i < 1 || i > opzioni.size())
        cout << "\tOperazione annullata." << endl;

      biblioteca.riconsegna(opzioni[i - 1]);
      cout << "\tLibro riconsegnato!" << endl;
      break;
    }
    case 7:
      biblioteca.stampaLibriPrestati();
      break;
    case 8:
      biblioteca.stampaClientiConLibroInPrestito();
      break;
    }
  } while (azione > 0 && azione <= 8);

  return 0;
}
