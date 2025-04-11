#include "findLabelValue.h"
#include "removeWhitespace.h"

std::string findLabelValue(std::string buffer, std::string label) {
  std::string value = "";
  std::size_t pos = buffer.find(label);

  if (pos != std::string::npos) {
    std::size_t end_pos = buffer.find('\n', pos + label.length());
    if (end_pos != std::string::npos) {
      value = removeWhitespace(
          buffer.substr(pos + label.length(), end_pos - pos - label.length()));
    }
  }
  return value;
}
