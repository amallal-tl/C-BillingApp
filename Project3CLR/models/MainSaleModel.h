#pragma once
#include <msclr/marshal_cppstd.h> // include this header file
#include "rapidjson/document.h"
using namespace System;

ref class MainSaleModel { // use ref class instead of class
public:
    System::String^ uniqueSaleId; // use System::String^ instead of String^
    System::String^ saleItem;
    System::String^ saleQuantity;
    int saleAmount;

    MainSaleModel(System::String^ id, System::String^ item, System::String^ quantity, int amount) {
        uniqueSaleId = id;
        saleItem = item;
        saleQuantity = quantity;
        saleAmount = amount;
    }

    array<MainSaleModel>^ jsonToMainSaleModel(System::String^ response) { // use array<MainSaleModel>^ instead of std::vector<MainSaleModel>
        // convert System::String^ to const char*
        msclr::interop::marshal_context ctx;
        const char* cstr = ctx.marshal_as<const char*>(response);

        // create a document object and parse the JSON string
        rapidjson::Document doc;
        doc.Parse(cstr);

        // check for parse errors
        if (doc.HasParseError()) {

            return nullptr;
        }

        array<MainSaleModel>^ mainSaleArray = gcnew array<MainSaleModel>(doc.Size()); // use gcnew instead of new

        // check if the document is an array
        if (doc.IsArray()) {
            // iterate over the array elements
            for (rapidjson::SizeType i = 0; i < doc.Size(); i++) {
                // check if the element is an object
                if (doc[i].IsObject()) {
                    // create a Sale object
                    MainSaleModel sale;

                    // check and get the uniqueSaleId member
                    if (doc[i].HasMember("uniqueSaleId") && doc[i]["uniqueSaleId"].IsString()) {
                        sale.uniqueSaleId = gcnew System::String(doc[i]["uniqueSaleId"].GetString()); // use gcnew to create a System::String^ from a char*
                    }

                    // check and get the saleItem member
                    if (doc[i].HasMember("saleItem") && doc[i]["saleItem"].IsString()) {
                        sale.saleItem = gcnew System::String(doc[i]["saleItem"].GetString());
                    }

                    // check and get the saleQuantity member
                    if (doc[i].HasMember("saleQuantity") && doc[i]["saleQuantity"].IsString()) {
                        sale.saleQuantity = gcnew System::String(doc[i]["saleQuantity"].GetString());
                    }

                    // check and get the saleAmount member
                    if (doc[i].HasMember("saleAmount") && doc[i]["saleAmount"].IsInt()) {
                        sale.saleAmount = doc[i]["saleAmount"].GetInt();
                    }

                    mainSaleArray[i] = sale; // assign the Sale object to the array element

                    // print the Sale object
                    sale.print();
                }
            }
        }
        return mainSaleArray;
    }

    MainSaleModel() {
        // default constructor
    }

    void print() {

        /*       System::Console::WriteLine("Sale ID: " + uniqueSaleId); // use System::Console::WriteLine instead of std::cout
               System::Console::WriteLine("Sale Item: " + saleItem);
               System::Console::WriteLine("Sale Quantity: " + saleQuantity);
               System::Console::WriteLine("Sale Amount: " + saleAmount);*/
    }
};
