
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_w3c_dom_css_CSSStyleSheet__
#define __org_w3c_dom_css_CSSStyleSheet__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace org
  {
    namespace w3c
    {
      namespace dom
      {
          class Node;
        namespace css
        {
            class CSSRule;
            class CSSRuleList;
            class CSSStyleSheet;
        }
        namespace stylesheets
        {
            class MediaList;
            class StyleSheet;
        }
      }
    }
  }
}

class org::w3c::dom::css::CSSStyleSheet : public ::java::lang::Object
{

public:
  virtual ::org::w3c::dom::css::CSSRule * getOwnerRule() = 0;
  virtual ::org::w3c::dom::css::CSSRuleList * getCssRules() = 0;
  virtual jint insertRule(::java::lang::String *, jint) = 0;
  virtual void deleteRule(jint) = 0;
  virtual ::java::lang::String * getType() = 0;
  virtual jboolean getDisabled() = 0;
  virtual void setDisabled(jboolean) = 0;
  virtual ::org::w3c::dom::Node * getOwnerNode() = 0;
  virtual ::org::w3c::dom::stylesheets::StyleSheet * getParentStyleSheet() = 0;
  virtual ::java::lang::String * getHref() = 0;
  virtual ::java::lang::String * getTitle() = 0;
  virtual ::org::w3c::dom::stylesheets::MediaList * getMedia() = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __org_w3c_dom_css_CSSStyleSheet__
