#include <iostream>
#include <flatbuffers/flatbuffers.h>
#include "person_generated.h"
using namespace std;

int main(){
	flatbuffers::FlatBufferBuilder builder;
	auto name = builder.CreateString("Mikhail");
	short age = 99;
	auto surname = builder.CreateString("Kasparyan");
	auto person = InnoPlusPlus::example_1::CreatePerson(builder, name, age, surname);
	builder.Finish(person);
	uint8_t* buf = builder.GetBufferPointer();
	int sz = builder.GetSize();
	
	for (int i = 0; i < sz; ++i) {
		cout << static_cast<int>(buf[i]) << " ";
	}

	auto parsed_person = InnoPlusPlus::example_1::GetPerson(buf);
	cout << endl << parsed_person->name()->str();
    return 0;
}
