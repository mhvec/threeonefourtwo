#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

float bAVG(vector<string> vBrand, vector<float> vPrice, string brand) {
  int count = 0; 
  float total = 0;
  for (int j = 0; j < vPrice.size(); j++) {
    if (vBrand[j].compare(brand) == 0){
      count = count + 1;
      total = total + vPrice[j];
    }
  }
  float avg = total / count;
  return avg;
}

float cAVG(vector<string> vCategory, vector<float> vPrice, string category) {
  int count = 0; 
  float total = 0;
  for (int j = 0; j < vPrice.size(); j++) {
    if (vCategory[j].compare(category) ==0) {
      count = count + 1;
      total = total + vPrice[j];
    }
  }
  float avg = total / count;
  return avg;
}

void byYear(vector<int> vSKU, vector<int> vYear, ofstream& out_stream) {  
    int count = 0; 
    float total = 0;
    vector<int> perYear;
    vector<int> skuCount;
    perYear.push_back(2000);
    perYear.push_back(2010);
    perYear.push_back(2020);

  for (int i = 0; i < perYear.size(); i++) {
    for (int j = 0; j < vSKU.size(); j++) {
    if (vYear[j] == perYear[i]) {
      skuCount.push_back(vSKU[j]);
        }
    }

  out_stream << perYear[i] << " (" << skuCount.size() << "): ";
  for (int j = 0; j < skuCount.size(); j++){
    out_stream << skuCount[j];
    if (j != skuCount.size() - 1) {
        out_stream << ", ";
    }
  }

  out_stream << endl;
  skuCount.clear();
  }
  out_stream << endl;
}

int main() {

  // define variables
  string sku, brand, category, year, price;
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;
  vector<string>uniqueBrand;

  ifstream in_stream;
  in_stream.open("data.csv"); //opening the file.

  if (in_stream.is_open()) { //if the file is open

    string line;

    while (!in_stream.eof()) { //while the end of file is NOT reached

     // Fields: sku,brand,category,year,price
     
     getline(in_stream, sku, ',');
     stringstream ssku(sku);
     int iSKU = 0;
     ssku >> iSKU;
     vSKU.push_back(iSKU);

     getline(in_stream, brand, ',');
     vBrand.push_back(brand);

     getline(in_stream, category, ',');
     vCategory.push_back(category);

     getline(in_stream, year, ',');
     stringstream syear(year);
     int iYear;
     syear >> iYear;
     vYear.push_back(iYear);

     getline(in_stream, price, '\n');
     stringstream sprice(price);
     float fPrice;
     sprice >> fPrice;
     vPrice.push_back(fPrice);
     
    }

    in_stream.close(); //close the file

    //write to output file
    ofstream out_stream;
    out_stream.open("output.txt");

   } else {
    cout << "Unable to open file"; 
   }
 
    ofstream out_stream;
    out_stream.open("output.txt");

    //output values to terminal
    cout << "SKU" << "\t" << "Brand" << "\t" << "Year" << endl; 
    out_stream << "Read Values\n" << "SKU" << "\t" << "Brand" << "\t" << "Year" << endl; 

    for (int j = 1; j < vSKU.size(); j++) {
        cout << vSKU[j] << "\t" << vBrand[j] << "\t" << vYear[j] << endl;
        out_stream << vSKU[j] << "\t" << vBrand[j] << "\t" << vYear[j] << endl;
    }

  
        out_stream << endl;
        out_stream << "Brand" << "\t" << "Average Price" << endl;
        brand = "ABC";
        out_stream << brand << "\t$" << bAVG(vBrand, vPrice, brand) << endl;
        brand = "XYZ";
        out_stream << brand << "\t$" << bAVG(vBrand, vPrice, brand) << endl;

        out_stream << endl;
        out_stream << "Category" << "\t" << "Average Price" << endl;
        category = "A";
        out_stream << category << "\t\t$" << cAVG(vCategory, vPrice, category) << endl;
        category = "B";
        out_stream << category << "\t\t$" << cAVG(vCategory, vPrice, category) << endl;
        category = "C";
        out_stream << category << "\t\t$" << cAVG(vCategory, vPrice, category) << endl;

        out_stream << endl;
        out_stream << "SKU by Year" << endl;
        byYear(vSKU,vYear,out_stream);

  cout << endl;
}
