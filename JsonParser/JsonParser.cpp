#include <iostream>
#include <ctime>

#include "Json.h"

using namespace std;

int main()
{
    //system("chcp 65001");

    string buffer = R"([
  {
    "_id": "63f06a8f4a5915284d5182b1",
    "index": 0,
    "guid": "5de5cd1d-d492-4740-a049-bec80838223e",
    "isActive": false,
    "balance": "$1,592.99",
    "picture": "http://placehold.it/32x32",
    "age": 22,
    "eyeColor": "blue",
    "name": "Perez Abbott",
    "gender": "male",
    "company": "SHEPARD",
    "email": "perezabbott@shepard.com",
    "phone": "+1 (837) 418-2943",
    "address": "927 Hall Street, Alafaya, Virginia, 8269",
    "about": "Mollit velit non elit laborum duis ea cillum. Consequat nulla sit minim exercitation sit ullamco commodo. Occaecat cupidatat Lorem ad id. Fugiat commodo dolor qui voluptate.\r\n",
    "registered": "2020-05-20T11:02:21 -08:00",
    "latitude": 85.8857,
    "longitude": -128.09632,
    "tags": [
      "mollit",
      "laborum",
      "aliqua",
      "mollit",
      "officia",
      "incididunt",
      "deserunt"
    ],
    "friends": [
      {
        "id": 0,
        "name": "Cobb Sykes"
      },
      {
        "id": 1,
        "name": "Hebert Powers"
      },
      {
        "id": 2,
        "name": "Higgins Calhoun"
      }
    ],
    "greeting": "Hello, Perez Abbott! You have 3 unread messages.",
    "favoriteFruit": "apple"
  },
  {
    "_id": "63f06a8f4f0f970052f3bcd4",
    "index": 1,
    "guid": "8d5a4fb7-f2f6-4495-bc24-5d75428a34a2",
    "isActive": true,
    "balance": "$3,160.35",
    "picture": "http://placehold.it/32x32",
    "age": 28,
    "eyeColor": "brown",
    "name": "Britt Hendricks",
    "gender": "male",
    "company": "NURALI",
    "email": "britthendricks@nurali.com",
    "phone": "+1 (824) 412-3488",
    "address": "495 Little Street, Smeltertown, Missouri, 1927",
    "about": "Elit velit laboris reprehenderit esse sit quis eiusmod dolore duis mollit voluptate sint in. Sint nisi et occaecat consectetur et enim eu elit. Elit nostrud deserunt sint magna cillum commodo et excepteur.\r\n",
    "registered": "2017-11-17T03:30:37 -08:00",
    "latitude": 73.605244,
    "longitude": -153.001718,
    "tags": [
      "dolor",
      "nisi",
      "commodo",
      "enim",
      "fugiat",
      "ea",
      "laboris"
    ],
    "friends": [
      {
        "id": 0,
        "name": "Moran Acevedo"
      },
      {
        "id": 1,
        "name": "Nola Hayden"
      },
      {
        "id": 2,
        "name": "Esperanza Hess"
      }
    ],
    "greeting": "Hello, Britt Hendricks! You have 6 unread messages.",
    "favoriteFruit": "strawberry"
  },
  {
    "_id": "63f06a8f5c4330be41d029a6",
    "index": 2,
    "guid": "5e98e1fe-5217-4440-83a6-4e1e61713e74",
    "isActive": false,
    "balance": "$3,126.70",
    "picture": "http://placehold.it/32x32",
    "age": 39,
    "eyeColor": "green",
    "name": "Cathryn Dawson",
    "gender": "female",
    "company": "GEEKOSIS",
    "email": "cathryndawson@geekosis.com",
    "phone": "+1 (863) 565-3653",
    "address": "216 Falmouth Street, Drummond, Maine, 1812",
    "about": "Tempor enim officia magna in officia ipsum ut labore. Ullamco pariatur ipsum sunt est ex elit mollit tempor pariatur dolore quis aliqua. Dolor voluptate in duis laborum. Incididunt ipsum duis fugiat culpa aliqua aute minim. Ea mollit est sit ipsum fugiat incididunt ea reprehenderit fugiat.\r\n",
    "registered": "2018-07-13T11:13:44 -08:00",
    "latitude": -19.29825,
    "longitude": -165.520362,
    "tags": [
      "sint",
      "ipsum",
      "duis",
      "irure",
      "nulla",
      "non",
      "nulla"
    ],
    "friends": [
      {
        "id": 0,
        "name": "Liliana Tran"
      },
      {
        "id": 1,
        "name": "Jeannie Oconnor"
      },
      {
        "id": 2,
        "name": "Pruitt Glass"
      }
    ],
    "greeting": "Hello, Cathryn Dawson! You have 5 unread messages.",
    "favoriteFruit": "strawberry"
  },
  {
    "_id": "63f06a8f6d859ac5c783f1d4",
    "index": 3,
    "guid": "760a2400-29a4-4de5-9d28-7a852eeaf331",
    "isActive": true,
    "balance": "$1,541.16",
    "picture": "http://placehold.it/32x32",
    "age": 35,
    "eyeColor": "green",
    "name": "Shawna Gardner",
    "gender": "female",
    "company": "LYRICHORD",
    "email": "shawnagardner@lyrichord.com",
    "phone": "+1 (954) 442-2796",
    "address": "106 Louise Terrace, Sexton, Kentucky, 7879",
    "about": "Aute aute ipsum labore in occaecat eiusmod aliqua ipsum elit. Qui nulla consequat esse adipisicing sit cillum adipisicing mollit laboris reprehenderit ipsum cillum duis officia. Aute commodo est cupidatat sit dolor. Minim esse fugiat sunt mollit laborum voluptate.\r\n",
    "registered": "2016-08-07T09:44:01 -08:00",
    "latitude": -47.243325,
    "longitude": 149.239252,
    "tags": [
      "veniam",
      "irure",
      "in",
      "veniam",
      "pariatur",
      "incididunt",
      "consectetur"
    ],
    "friends": [
      {
        "id": 0,
        "name": "Felecia Shannon"
      },
      {
        "id": 1,
        "name": "Rice Ruiz"
      },
      {
        "id": 2,
        "name": "Koch Hahn"
      }
    ],
    "greeting": "Hello, Shawna Gardner! You have 2 unread messages.",
    "favoriteFruit": "apple"
  },
  {
    "_id": "63f06a8fd369caff90e498e2",
    "index": 4,
    "guid": "dc6bb67b-4f25-4141-bc0b-e904e3a4fec6",
    "isActive": false,
    "balance": "$2,512.09",
    "picture": "http://placehold.it/32x32",
    "age": 31,
    "eyeColor": "brown",
    "name": "Cindy Dodson",
    "gender": "female",
    "company": "MIXERS",
    "email": "cindydodson@mixers.com",
    "phone": "+1 (918) 401-3911",
    "address": "965 Monroe Place, Why, Michigan, 4369",
    "about": "Pariatur aliquip officia aute minim culpa deserunt occaecat exercitation consectetur ullamco reprehenderit Lorem cillum eiusmod. Excepteur ullamco aliquip non laborum veniam et veniam dolor dolor exercitation laboris elit sint laborum. Cillum est laboris sit qui est et ex.\r\n",
    "registered": "2016-06-22T07:55:57 -08:00",
    "latitude": -16.424642,
    "longitude": 66.293929,
    "tags": [
      "tempor",
      "enim",
      "tempor",
      "ullamco",
      "id",
      "ipsum",
      "voluptate"
    ],
    "friends": [
      {
        "id": 0,
        "name": "Santana Wiley"
      },
      {
        "id": 1,
        "name": "Albert Francis"
      },
      {
        "id": 2,
        "name": "Bernard Blackburn"
      }
    ],
    "greeting": "Hello, Cindy Dodson! You have 7 unread messages.",
    "favoriteFruit": "apple"
  },
  {
    "_id": "63f06a8f6f1d085b8a3553e9",
    "index": 5,
    "guid": "09ca459a-5a6f-4e41-8d62-3f1aab4010f1",
    "isActive": true,
    "balance": "$2,455.00",
    "picture": "http://placehold.it/32x32",
    "age": 37,
    "eyeColor": "blue",
    "name": "Pam Lynch",
    "gender": "female",
    "company": "PHUEL",
    "email": "pamlynch@phuel.com",
    "phone": "+1 (855) 407-3112",
    "address": "497 Micieli Place, Jacumba, Northern Mariana Islands, 2059",
    "about": "Cupidatat occaecat velit ea Lorem dolore culpa sint Lorem ipsum. Culpa duis pariatur ad esse excepteur ad. Labore sunt fugiat duis minim anim. Cillum laborum et laborum sunt magna reprehenderit sit tempor.\r\n",
    "registered": "2023-02-01T04:30:57 -08:00",
    "latitude": -87.241294,
    "longitude": 126.858022,
    "tags": [
      "magna",
      "dolor",
      "dolore",
      "adipisicing",
      "officia",
      "commodo",
      "non"
    ],
    "friends": [
      {
        "id": 0,
        "name": "Kent Mccoy"
      },
      {
        "id": 1,
        "name": "Shelby Glenn"
      },
      {
        "id": 2,
        "name": "Greer Chase"
      }
    ],
    "greeting": "Hello, Pam Lynch! You have 1 unread messages.",
    "favoriteFruit": "strawberry"
  }
])";
    clock_t start = clock();
    int length = 1000;
    for (size_t i = 0; i < length; i++)
    {
        qjson::JObject json = qjson::JParser::fastParse(buffer);
        auto get = qjson::JWriter::fastWrite(json);
    }
    cout << (clock() - start) * 1.0 / CLOCKS_PER_SEC / length << "\n";
    
    return 0;
}
