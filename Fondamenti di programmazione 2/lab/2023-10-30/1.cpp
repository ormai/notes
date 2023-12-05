#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout, std::endl;

class File {
protected:
  string nome{""};
  unsigned dimensione{0}; // dimensione in byte

public:
  File() = default;
  File(const string &_nome, const unsigned &_dimensione)
      : nome(_nome), dimensione(_dimensione) {}
  File(const File &file)
      : nome(file.getNome()), dimensione(file.getDimensione()) {}

  File &operator=(const File &file) {
    nome = file.getNome();
    dimensione = file.getDimensione();
    return *this;
  }

  void rinomina(const string &nuovoNome) { nome = nuovoNome; }

  string getNome() const { return nome; }
  unsigned getDimensione() const { return dimensione; }
};

class FilePdf : public File {
private:
  bool firmato{false};

public:
  FilePdf() = default;
  FilePdf(const string &_nome, const unsigned &_dimensione, const bool _firmato)
      : File(_nome, _dimensione), firmato(_firmato) {}
  FilePdf(const FilePdf &pdf)
      : File(pdf.getNome(), pdf.getDimensione()), firmato(pdf.eFirmato()) {}

  FilePdf &operator=(const FilePdf &pdf) {
    nome = pdf.getNome();
    dimensione = pdf.getDimensione();
    firmato = pdf.eFirmato();
    return *this;
  }

  bool eFirmato() const { return firmato; }
};

class FileAudio : public File {
private:
  unsigned durata{0}; // durata in secondi

public:
  FileAudio() = default;
  FileAudio(const string &_nome, const unsigned &_dimensione,
            const unsigned &_durata)
      : File(_nome, _dimensione), durata(_durata) {}
  FileAudio(const FileAudio &audio)
      : File(audio.getNome(), audio.getDimensione()),
        durata(audio.getDurata()) {}

  FileAudio &operator=(const FileAudio &audio) {
    nome = audio.getNome();
    dimensione = audio.getDurata();
    durata = audio.getDurata();
    return *this;
  }

  unsigned getDurata() const { return durata; }
};

class FileArchivio : public File {
  vector<File *> archivio{};
  double fattoreDiCompressione{0.0};

public:
  FileArchivio() = default;
  FileArchivio(const double &_fattoreDiCompressionee)
      : fattoreDiCompressione(_fattoreDiCompressionee) {}
  FileArchivio(const FileArchivio &fa)
      : File(fa.getNome(), fa.getDimensione()),
        fattoreDiCompressione(fa.getFattoreDiCompressione()) {
    for (unsigned i = 0; i < fa.getNumeroFile(); ++i)
      archivio.push_back(fa[i]);
  }

  double getFattoreDiCompressione() const { return fattoreDiCompressione; }
  void setFattoreDiCompressione(const double &_fattoreDiCompressione) {
    fattoreDiCompressione = _fattoreDiCompressione;
  }
  unsigned getDimensione() const;
  void archivia(File *file) { archivio.push_back(file); }
  unsigned getNumeroFile() const { return archivio.size(); }

  File *operator[](const unsigned i) const { return archivio[i]; }
  File *&operator[](const unsigned i) { return archivio[i]; }

  FileArchivio &operator=(const FileArchivio &fa) {
    nome = fa.getNome();
    dimensione = fa.getDimensione();

    for (unsigned i = 0; i < fa.getNumeroFile(); ++i)
      archivio.push_back(fa[i]);

    fattoreDiCompressione = fa.getFattoreDiCompressione();

    return *this;
  }
};

unsigned FileArchivio::getDimensione() const {
  unsigned dimensioneArchivio = 0;
  for (unsigned i = 0; i < archivio.size(); ++i)
    dimensioneArchivio += archivio[i]->getDimensione();
  return dimensioneArchivio * fattoreDiCompressione;
}

int main() {
  // TESTING
  FilePdf manualeCPP("C++ Primer.pdf", 46336275, false);
  FileAudio numb("LinkinPark-Numb.mp3", 368742, 185);
  File appunti("Polimorfismo.txt", 1762);

  FileArchivio zip(0.7);
  zip.archivia(&manualeCPP);
  zip.archivia(&numb);
  zip.archivia(&appunti);

  cout << zip.getDimensione() << endl;

  return 0;
}
