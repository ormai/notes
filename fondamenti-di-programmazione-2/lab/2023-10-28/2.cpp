#include <iostream>
using std::ostream, std::cout, std::cin, std::endl;
#include <stack>
#include <string>
using std::string, std::to_string;
#include <assert.h>

class Browser {
private:
  std::stack<string> pastPages{};
  string currentPage{"https://google.com"};
  std::stack<string> futurePages{};

public:
  Browser() = default;
  string getCurrentPage() const { return currentPage; };
  string getCount() const;

  void visitNewPage(const string &page);
  void goBackOnePage();
  void goForwardOnePage();

  friend ostream &operator<<(ostream &os, const Browser &browser) {
    os << "[Current Page: " << browser.getCurrentPage() << "] ["
       << browser.getCount() << ']';
    return os;
  }
};

void Browser::goForwardOnePage() {
  assert(futurePages.empty());
  pastPages.push(currentPage);
  currentPage = futurePages.top();
  futurePages.pop();
}

void Browser::goBackOnePage() {
  assert(pastPages.empty());
  futurePages.push(currentPage);
  currentPage = pastPages.top();
  pastPages.pop();
}

void Browser::visitNewPage(const string &page) {
  pastPages.push(currentPage);
  currentPage = page;
  futurePages = {}; // azzera
}

string Browser::getCount() const {
  /* Returns a string representing the number of pages preceding the current
   * and the number of pages following it, separated by a white space.
   */

  return to_string(pastPages.size()) + ' ' + to_string(futurePages.size());
}

int main() {
  Browser firefox;
  char action;
  do {
    cout << "Esegui un operazione:\n"
         << "  v · nuova pagina\n"
         << "  b · indietro\n"
         << "  f · avanti\n"
         << "  e · esci\n"
         << "> ";
    cin >> action;

    switch (action) {
    case 'v': {
      cout << "Indirizzo: ";
      string indirizzo;
      cin >> indirizzo;
      firefox.visitNewPage(indirizzo);
      break;
    }
    case 'b':
      firefox.goBackOnePage();
      break;
    case 'f':
      firefox.goForwardOnePage();
      break;
    case 'e':
      cout << firefox << endl;
      return 0;
    }
    cout << firefox << endl;

  } while (true);
}
