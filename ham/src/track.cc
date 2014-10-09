#include "track.h"

namespace ham {
      
// ----------------------------------------------------------------------------------------
Track::Track(string name, size_t n_seqs, vector<string> symbols) :
  name_(name),
  n_seqs_(n_seqs),
  track_index_(numeric_limits<size_t>::max())
{
  assert(n_seqs_ == 1 || n_seqs_ == 2);
  AddSymbols(symbols);
}
      
// ----------------------------------------------------------------------------------------
void Track::AddSymbol(string symbol) {
  assert(alphabet_.size() < 255);  // cannot (at the moment) have more than 255 symbols in an alphabet
  alphabet_.push_back(symbol);
  symbol_indices_[symbol] = alphabet_.size() - 1;
}
  
// ----------------------------------------------------------------------------------------
void Track::AddSymbols(vector<string> &symbols) {
  for(size_t i=0; i<symbols.size(); ++i)
    AddSymbol(symbols[i]);
}
  
// ----------------------------------------------------------------------------------------
uint8_t Track::symbol_index(const string &symbol) {
  if (symbol_indices_.count(symbol) == 0) {
    cerr << "ERROR symbol \"" << symbol << "\" not found among " << Stringify() << endl;
    assert(0);
  }
  return symbol_indices_[symbol];
}

// ----------------------------------------------------------------------------------------
string Track::Stringify() {
  string return_str;
  for (auto &symbol : alphabet_)
    return_str += " " + symbol;
  return return_str;
}

//****************************************************************************************
// ----------------------------------------------------------------------------------------
void Tracks::push_back(Track* tk){
  assert(indices_.count(tk->name()) == 0);  // cannot add two tracks with the same name
  indices_[tk->name()] = tracks_.size();
  tracks_.push_back(tk);
}

}
