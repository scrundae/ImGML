#include "include/tinyxml2.h"
#include "imgui.h"
#include <string>

using namespace tinyxml2;
using namespace std;

void ImInterpret(const char* filename) {
    XMLDocument doc;
    doc.LoadFile(filename);
    if (doc.ErrorID() != 0) {
        printf("Error: %s\n", doc.ErrorName());
        return;
    }

    XMLElement* currentNode = doc.FirstChildElement();

    while (currentNode != nullptr) {
        string text = currentNode->GetText();
        string type = currentNode->Value();
        if (type == "p") {
            ImGui::Text("%s", text.c_str());
        }
        else if (type == "button") {
            if (ImGui::Button(text.c_str())) {
            }
        }
        currentNode = currentNode->NextSiblingElement();
    }

}