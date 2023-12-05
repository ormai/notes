#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef pair<string, pair<unsigned, set<string>>> datum;

int main() {
  unordered_map<string, pair<unsigned, set<string>>> hashtags;

  unsigned n = 0;
  cout << "Numero di tweet: ";
  cin >> n;
  cin.ignore(); // altrimenti \n resta sullo stream e getline() termina subito

  for (unsigned i = 0; i < n; ++i) {
    string tweet = "";
    getline(cin, tweet);

    string::size_type start = tweet.find('#'), end = tweet.find(' ', start);

    while (start != string::npos) {
      string ht = tweet.substr(start, end - start);
      ++hashtags[ht].first;
      hashtags[ht].second.insert(tweet);

      start = tweet.find('#', start + 1);
      end = tweet.find(' ', start); // se non lo trova end = tweet.size()
    }
  }
  datum ciao;

  // è ipossibile ordinare un unordered_map
  vector<datum> hashtagsOrdinati;
  for (datum h : hashtags)
    hashtagsOrdinati.push_back(h); // copia

  sort(hashtagsOrdinati.begin(), hashtagsOrdinati.end(),
       [](const datum &l, const datum &r) {
         return l.second.first > r.second.first;
       });

  // structured binding
  for (auto &[hashtag, frequenza] : hashtagsOrdinati)
    cout << frequenza.first << " - " << hashtag << endl;

  // Secondo punto
  string richiesta = "";
  do {
    cout << "Hashtag: ";
    cin >> richiesta;

    if (hashtags.count(richiesta)) { // controlla che la chiave esista
      for (string ht : hashtags[richiesta].second)
        cout << '\t' << ht << '\n';
    }

    cout << "Hashtag: ";
  } while (cin >> richiesta); // terminato da CTRL+D

  return 0;
}
