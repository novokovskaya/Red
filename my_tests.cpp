#include "my_tests.h"

#include <vector>
#include <string>
#include <sstream>

#include "docs_generator.h"
#include "parse.h"
#include "search_server.h"
#include "profile.h"

using namespace std;

void TestBenchmark() {
  const vector<string> dict = MakeDictionary();

  const vector<string> docs = MakeSentencesSet(dict, 50'000, 1'000);
  const vector<string> queries = MakeSentencesSet(dict, 500'000, 10);

  istringstream docs_input(Join('\n', docs));
  istringstream queries_input(Join('\n', queries));

  SearchServer srv;
  {
    LOG_DURATION("UpdateDocumentBase")
    srv.UpdateDocumentBase(docs_input);
  }
  ostringstream queries_output;
  {
    LOG_DURATION("AddQueriesStream")
    srv.AddQueriesStream(queries_input, queries_output);
  }
}