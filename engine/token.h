#ifndef TOKEN_H
#define TOKEN_H
#include <engine/token.h>

enum class Token; //might not work with the classes

//If its not legal to declare enums in header without defining the enumerations,
//Just move Token definition into here, and move all the Tk____ to token.cpp, should be pretty general
//These sub-token enum types are really useful for parser logic, but aren't totally critical
enum class TkVerb;

enum class TkItem;

enum class TkScenery;

enum class TkPerson;

enum class TkSpecial;

typedef MergeEnum< Token, TokenVerb, TokenItem, TokenScenery, TokenPerson, TokenSpecial> Tk;


//Adapted from Lidzhade Fhulu https://www.codeproject.com/Articles/16150/Inheriting-a-C-enum-type

/***
template <typename BaseEnumT, typename EnumT >
class InheritEnum
{
public:
  InheritEnum() {}
  InheritEnum(EnumT e)
    : enum_(e)
  {}

  InheritEnum(BaseEnumT e)
    : baseEnum_(e)
  {}

  explicit InheritEnum( int val )
    : enum_(static_cast<EnumT>(val))
  {}

  operator EnumT() const { return enum_; }
private:
  // Note - the value is declared as a union mainly for as a debugging aid. If 
  // the union is undesired and you have other methods of debugging, change it
  // to either of EnumT and do a cast for the constructor that accepts BaseEnumT.
  union
  { 
    EnumT enum_;
    BaseEnumT baseEnum_;
  };
};
***/

//This probably won't work, need to iterate on it or maybe expand it to all tokens
template <typename BaseEnumT, typename... EnumsT >
class InheritEnum
{
public:
  InheritEnum() {}
  InheritEnum(EnumsT e)
    : enum_(e)
  {}

  InheritEnum(BaseEnumT e)
    : baseEnum_(e)
  {}

  explicit InheritEnum( int val )
    : enum_(static_cast<EnumsT>(val))
  {}

  operator EnumsT() const { return enum_; }
private:
  // Note - the value is declared as a union mainly for as a debugging aid. If 
  // the union is undesired and you have other methods of debugging, change it
  // to either of EnumT and do a cast for the constructor that accepts BaseEnumT.
  union
  { 
    EnumsT enum_;
    BaseEnumT baseEnum_;
  };
};

//App-defined function to iterate over all tokens and map command string to token vector
Vector<Token> tokenize_string(string input);

#endif