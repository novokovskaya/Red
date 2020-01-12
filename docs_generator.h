#pragma once

#include <string>
#include <vector>

std::vector<std::string> MakeDictionary();
std::string MakeSentence(const std::vector<std::string>& dict, int word_amount);
std::vector<std::string> MakeSentencesSet(
    const std::vector<std::string>& dict, int sentence_amount, int word_amount);