#include "docs_generator.h"

#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <random>

using namespace std;

vector<string> MakeDictionary() {
  // ifstream words ("google-10000-english-no-swears.txt");
  ifstream words ("google-10000-english.txt");

  vector<string> dict;
  dict.reserve(10'000);

  for (string word; getline(words, word);)
    dict.push_back(move(word));

  return dict;
}

string MakeSentence(const vector<string>& dict, int word_amount) {
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis_amount(1, word_amount);
  int rand_word_amount = dis_amount(gen);

  std::uniform_int_distribution<> dis(0, dict.size());

  string result;
  for (size_t i = 0; i < rand_word_amount; ++i) {
    result += dict[dis(gen)] + ' ';
  }

  return result;
}

vector<string> MakeSentencesSet(const vector<string>& dict, int sentence_amount, int word_amount) {
  // vector<string> dict = MakeDictionary();

  vector<string> sentences_set(sentence_amount);
  for (int i = 0; i < sentence_amount; ++i)
    sentences_set[i] = move(MakeSentence(dict, word_amount));

  return sentences_set;
}