# Transport Catalog

System allows clients to upload a Json request to create a database that contains information about
bus stops, bus numbers, bus routes and organizations. 

### Requirements
- C++ 17
- Google Protobuf
## Step 1. Create database

This request is handled with command line argument: __'make_base'__

It accepts as input a Json document passed to the standard input stream.

### Example Json

```json
{
    "serialization_settings": {
        "file": "/tmp/tmpqrfdop7w"
    },
    "routing_settings": {
        "bus_wait_time": 2,
        "bus_velocity": 30,
        "pedestrian_velocity": 4
    },
    "render_settings": {
        "width": 1500,
        "height": 950,
        "padding": 50,
        "outer_margin": 150,
        "stop_radius": 3,
        "company_radius": 5,
        "line_width": 10,
        "company_line_width": 2,
        "bus_label_font_size": 18,
        "bus_label_offset": [
            7,
            15
        ],
        "stop_label_font_size": 13,
        "stop_label_offset": [
            7,
            -3
        ],
        "underlayer_color": [
            255,
            255,
            255,
            0.85
        ],
        "underlayer_width": 3,
        "color_palette": [
            "red",
            "green",
            "blue",
            "brown",
            "orange"
        ],
        "layers": [
            "bus_lines",
            "company_lines",
            "bus_labels",
            "stop_points",
            "company_points",
            "stop_labels",
            "company_labels"
        ]
    },
    "base_requests": [
        {
            "type": "Bus",
            "name": "23",
            "stops": [
                "Санаторий Салют",
                "Санаторная улица",
                "Пансионат Нева",
                "Санаторий Радуга",
                "Санаторий Родина",
                "Спортивная",
                "Парк Ривьера",
                "Морской вокзал",
                "Органный зал",
                "Театральная",
                "Пансионат Светлана",
                "Цирк",
                "Стадион",
                "Санаторий Металлург",
                "Улица Бытха"
            ],
            "is_roundtrip": false
        },
        {
            "type": "Bus",
            "name": "13",
            "stops": [
                "Улица Лизы Чайкиной",
                "Пионерская улица, 111",
                "Садовая",
                "Театральная"
            ],
            "is_roundtrip": false
        },
        {
            "type": "Bus",
            "name": "36",
            "stops": [
                "Морской вокзал",
                "Сбербанк",
                "Автовокзал",
                "Отель Звёздный",
                "Магазин Быт",
                "Хлебозавод",
                "Кинотеатр Юбилейный",
                "Новая Заря",
                "Деревообр. комбинат",
                "Целинная улица, 5",
                "Целинная улица, 57",
                "Целинная улица"
            ],
            "is_roundtrip": false
        },
        {
            "type": "Bus",
            "name": "44к",
            "stops": [
                "Пансионат Светлана",
                "Улица Лысая Гора",
                "Улица В. Лысая Гора"
            ],
            "is_roundtrip": false
        },
        {
            "type": "Bus",
            "name": "90",
            "stops": [
                "Краево-Греческая улица",
                "Улица Бытха",
                "Санаторий им. Ворошилова",
                "Санаторий Приморье",
                "Санаторий Заря",
                "Мацеста",
                "Мацестинская долина"
            ],
            "is_roundtrip": false
        },
        {
            "type": "Stop",
            "name": "Краево-Греческая улица",
            "latitude": 43.565551,
            "longitude": 39.776858,
            "road_distances": {
                "Улица Бытха": 1780
            }
        },
        {
            "type": "Stop",
            "name": "Санаторий им. Ворошилова",
            "latitude": 43.557935,
            "longitude": 39.764452,
            "road_distances": {
                "Санаторий Приморье": 950
            }
        },
        {
            "type": "Stop",
            "name": "Санаторий Приморье",
            "latitude": 43.554202,
            "longitude": 39.77256,
            "road_distances": {
                "Санаторий Заря": 2350
            }
        },
        {
            "type": "Stop",
            "name": "Санаторий Заря",
            "latitude": 43.549618,
            "longitude": 39.780908,
            "road_distances": {
                "Мацеста": 800
            }
        },
        {
            "type": "Stop",
            "name": "Мацеста",
            "latitude": 43.545509,
            "longitude": 39.788993,
            "road_distances": {
                "Мацестинская долина": 2350
            }
        },
        {
            "type": "Stop",
            "name": "Мацестинская долина",
            "latitude": 43.560422,
            "longitude": 39.798219,
            "road_distances": {}
        },
        {
            "type": "Stop",
            "name": "Улица Лысая Гора",
            "latitude": 43.577997,
            "longitude": 39.741685,
            "road_distances": {
                "Улица В. Лысая Гора": 640
            }
        },
        {
            "type": "Stop",
            "name": "Улица В. Лысая Гора",
            "latitude": 43.58092,
            "longitude": 39.744749,
            "road_distances": {}
        },
        {
            "type": "Stop",
            "name": "Морской вокзал",
            "latitude": 43.581969,
            "longitude": 39.719848,
            "road_distances": {
                "Сбербанк": 870,
                "Органный зал": 570
            }
        },
        {
            "type": "Stop",
            "name": "Сбербанк",
            "latitude": 43.585969,
            "longitude": 39.725175,
            "road_distances": {
                "Автовокзал": 870
            }
        },
        {
            "type": "Stop",
            "name": "Автовокзал",
            "latitude": 43.592956,
            "longitude": 39.727798,
            "road_distances": {
                "Отель Звёздный": 700
            }
        },
        {
            "type": "Stop",
            "name": "Отель Звёздный",
            "latitude": 43.596585,
            "longitude": 39.721151,
            "road_distances": {
                "Магазин Быт": 1000
            }
        },
        {
            "type": "Stop",
            "name": "Магазин Быт",
            "latitude": 43.604025,
            "longitude": 39.724492,
            "road_distances": {
                "Хлебозавод": 420
            }
        },
        {
            "type": "Stop",
            "name": "Хлебозавод",
            "latitude": 43.607364,
            "longitude": 39.726643,
            "road_distances": {
                "Кинотеатр Юбилейный": 2110
            }
        },
        {
            "type": "Stop",
            "name": "Кинотеатр Юбилейный",
            "latitude": 43.623382,
            "longitude": 39.720626,
            "road_distances": {
                "Новая Заря": 450
            }
        },
        {
            "type": "Stop",
            "name": "Новая Заря",
            "latitude": 43.626842,
            "longitude": 39.717802,
            "road_distances": {
                "Деревообр. комбинат": 530
            }
        },
        {
            "type": "Stop",
            "name": "Деревообр. комбинат",
            "latitude": 43.631035,
            "longitude": 39.714624,
            "road_distances": {
                "Целинная улица, 5": 840
            }
        },
        {
            "type": "Stop",
            "name": "Целинная улица, 5",
            "latitude": 43.633353,
            "longitude": 39.710257,
            "road_distances": {
                "Целинная улица, 57": 1270
            }
        },
        {
            "type": "Stop",
            "name": "Целинная улица, 57",
            "latitude": 43.640536,
            "longitude": 39.713253,
            "road_distances": {
                "Целинная улица": 1050
            }
        },
        {
            "type": "Stop",
            "name": "Целинная улица",
            "latitude": 43.647968,
            "longitude": 39.717733,
            "road_distances": {}
        },
        {
            "type": "Stop",
            "name": "Санаторий Салют",
            "latitude": 43.623238,
            "longitude": 39.704646,
            "road_distances": {
                "Санаторная улица": 1500
            }
        },
        {
            "type": "Stop",
            "name": "Санаторная улица",
            "latitude": 43.620766,
            "longitude": 39.719058,
            "road_distances": {
                "Пансионат Нева": 670
            }
        },
        {
            "type": "Stop",
            "name": "Пансионат Нева",
            "latitude": 43.614288,
            "longitude": 39.718674,
            "road_distances": {
                "Санаторий Радуга": 520
            }
        },
        {
            "type": "Stop",
            "name": "Санаторий Радуга",
            "latitude": 43.609951,
            "longitude": 39.72143,
            "road_distances": {
                "Санаторий Родина": 1190
            }
        },
        {
            "type": "Stop",
            "name": "Санаторий Родина",
            "latitude": 43.601202,
            "longitude": 39.715498,
            "road_distances": {
                "Спортивная": 1100
            }
        },
        {
            "type": "Stop",
            "name": "Спортивная",
            "latitude": 43.593689,
            "longitude": 39.717642,
            "road_distances": {
                "Парк Ривьера": 640
            }
        },
        {
            "type": "Stop",
            "name": "Парк Ривьера",
            "latitude": 43.588296,
            "longitude": 39.715956,
            "road_distances": {
                "Морской вокзал": 730
            }
        },
        {
            "type": "Stop",
            "name": "Органный зал",
            "latitude": 43.57926,
            "longitude": 39.725574,
            "road_distances": {
                "Театральная": 770
            }
        },
        {
            "type": "Stop",
            "name": "Пансионат Светлана",
            "latitude": 43.571807,
            "longitude": 39.735866,
            "road_distances": {
                "Цирк": 520,
                "Улица Лысая Гора": 1070
            }
        },
        {
            "type": "Stop",
            "name": "Цирк",
            "latitude": 43.569207,
            "longitude": 39.739869,
            "road_distances": {
                "Стадион": 860
            }
        },
        {
            "type": "Stop",
            "name": "Стадион",
            "latitude": 43.565301,
            "longitude": 39.749485,
            "road_distances": {
                "Санаторий Металлург": 950
            }
        },
        {
            "type": "Stop",
            "name": "Санаторий Металлург",
            "latitude": 43.561005,
            "longitude": 39.760511,
            "road_distances": {
                "Улица Бытха": 900
            }
        },
        {
            "type": "Stop",
            "name": "Улица Бытха",
            "latitude": 43.566135,
            "longitude": 39.762109,
            "road_distances": {
                "Санаторий им. Ворошилова": 1160
            }
        },
        {
            "type": "Stop",
            "name": "Улица Лизы Чайкиной",
            "latitude": 43.590317,
            "longitude": 39.746833,
            "road_distances": {
                "Пионерская улица, 111": 950
            }
        },
        {
            "type": "Stop",
            "name": "Пионерская улица, 111",
            "latitude": 43.587257,
            "longitude": 39.740325,
            "road_distances": {
                "Садовая": 520
            }
        },
        {
            "type": "Stop",
            "name": "Садовая",
            "latitude": 43.58395,
            "longitude": 39.736938,
            "road_distances": {
                "Театральная": 1300
            }
        },
        {
            "type": "Stop",
            "name": "Театральная",
            "latitude": 43.57471,
            "longitude": 39.731954,
            "road_distances": {
                "Пансионат Светлана": 390
            }
        }
    ],
    "yellow_pages": {
        "rubrics": {
            "1": {
                "name": "Парк"
            }
        },
        "companies": [
            {
                "names": [
                    {
                        "value": "Дендрарий"
                    }
                ],
                "urls": [
                    {
                        "value": "http://dendrarium.ru"
                    }
                ],
                "rubrics": [
                    1
                ],
                "address": {
                    "coords": {
                        "lat": "43.573226",
                        "lon": "39.742947"
                    }
                },
                "nearby_stops": [
                    {
                        "name": "Цирк",
                        "meters": 180
                    }
                ],
                "phones": [
                    {
                        "type": "PHONE",
                        "country_code": "7",
                        "local_code": "862",
                        "number": "2671646"
                    },
                    {
                        "type": "PHONE",
                        "country_code": "7",
                        "local_code": "862",
                        "number": "2671842"
                    }
                ],
                "working_time": {
                    "intervals": [
                        {
                            "day": "EVERYDAY",
                            "minutes_from": 540,
                            "minutes_to": 1020
                        }
                    ]
                }
            },
            {
                "names": [
                    {
                        "value": "им. Фрунзе"
                    }
                ],
                "rubrics": [
                    1
                ],
                "address": {
                    "coords": {
                        "lat": "43.567998",
                        "lon": "39.734131"
                    }
                },
                "nearby_stops": [
                    {
                        "name": "Пансионат Светлана",
                        "meters": 580
                    },
                    {
                        "name": "Цирк",
                        "meters": 700
                    },
                    {
                        "name": "Театральная",
                        "meters": 1000
                    }
                ]
            }
        ]
    }
}
```
At this stage the database is created and filled with all the necessary information. It gets serialized
by means of Google Protobuf. 

### A Bus description contains:
- name
- stops
- bool flag that indicates if the bus route is round trip or not

### A Stop description contains:
- name
- latitude (geographical location)
- longitude (geographical location)
- road distances to other stops (optional). If it is not provided in the Json, then it is calculated as the direct distance between two positions on the Earth provided by longitudes and latitudes of the stops.

### A Company description contains:
- names (possible names of a company)
- urls (urls of websites of a company)
- rubrics (rubrics the company is associated with), complete list of rubrics is passed in the Json document as well
- address (geographical coordinates of the company)
- nearby stops and distances to them
- phones
- working time intervals

### The input Json also contains:
- Serialization settings (name of the file the database is serialized into)
- Routing settings (specifies bus wait time, bus velocity and pedestrian velocity)
- Render settings (specifies various settings for the output of SVG document)

## Step 2. Process Requests to Database

This request is handled with command line argument: 'process_requests'.

It accepts as input a Json document passed to the standard input stream.

## Example Json

```json
{
    "serialization_settings": {
        "file": "/tmp/tmpqrfdop7w"
    },
    "stat_requests": [
        {
            "id": 1976763663,
            "type": "Bus",
            "name": "13"
        },
        {
            "id": 1208333195,
            "type": "Stop",
            "name": "Морской вокзал"
        },
        {
            "id": 275341641,
            "type": "FindCompanies",
            "rubrics": [
                "Парк"
            ]
        },
        {
            "id": 1142770959,
            "type": "Route",
            "from": "Краево-Греческая улица",
            "to": "Органный зал"
        },
        {
            "id": 940120142,
            "type": "RouteToCompany",
            "from": "Краево-Греческая улица",
            "companies": {
                "rubrics": [
                    "Парк"
                ]
            },
            "datetime": [
                6,
                8,
                35
            ]
        },
        {
            "id": 1054152420,
            "type": "RouteToCompany",
            "from": "Краево-Греческая улица",
            "companies": {
                "rubrics": [
                    "Парк"
                ]
            },
            "datetime": [
                6,
                8,
                40
            ]
        }
    ]
}
```

The Json contains various requests to the database.

### Bus

Shows information about a bus route. 
- route length
- number of stops
- number of unique stops

### Stop

Shows information about a stop - which busses bass through the stop. 

### FindCompanies

Shows information about a company (company main name), that satisfies criteria passed in Json.

### RouteToCompany

Shows information about the fastest route to a company that satisfies criteria passed in Json. 
Route to company is represented as an SVG object.

### Route

Shows information about the fastest route from one stop to another. 
Route between stops is represented as an SVG object. 

### Example output Json (based on the above input).

```json
[
  {
    "curvature": 1.26723,
    "request_id": 1976763663,
    "route_length": 5540,
    "stop_count": 7,
    "unique_stop_count": 4
  },
  {
    "buses": [
      "23",
      "36"
    ],
    "request_id": 1208333195
  },
  {
    "companies": [
      "Дендрарий",
      "им. Фрунзе"
    ],
    "request_id": 275341641
  },
  {
    "items": [
      {
        "stop_name": "Краево-Греческая улица",
        "time": 2,
        "type": "WaitBus"
      },
      {
        "bus": "90",
        "span_count": 1,
        "time": 3.56,
        "type": "RideBus"
      },
      {
        "stop_name": "Улица Бытха",
        "time": 2,
        "type": "WaitBus"
      },
      {
        "bus": "23",
        "span_count": 6,
        "time": 8.78,
        "type": "RideBus"
      }
    ],
    "map": "<?xml version=\"1.0\" encoding=\"UTF-8\" ?><svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"><polyline points=\"983.333,419.565 925,456.522 866.667,493.478 808.333,530.435 866.667,493.478 925,456.522 983.333,419.565 \" fill=\"none\" stroke=\"red\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"50,197.826 108.333,234.783 166.667,271.739 225,308.696 283.333,345.652 341.667,382.609 400,419.565 691.667,456.522 750,493.478 808.333,530.435 925,567.391 983.333,604.348 1041.67,641.304 1100,678.261 1158.33,715.217 1100,678.261 1041.67,641.304 983.333,604.348 925,567.391 808.333,530.435 750,493.478 691.667,456.522 400,419.565 341.667,382.609 283.333,345.652 225,308.696 166.667,271.739 108.333,234.783 50,197.826 \" fill=\"none\" stroke=\"green\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"691.667,456.522 633.333,419.565 575,382.609 516.667,345.652 458.333,308.696 400,271.739 341.667,234.783 283.333,197.826 225,160.87 166.667,123.913 108.333,86.9565 50,50 108.333,86.9565 166.667,123.913 225,160.87 283.333,197.826 341.667,234.783 400,271.739 458.333,308.696 516.667,345.652 575,382.609 633.333,419.565 691.667,456.522 \" fill=\"none\" stroke=\"blue\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"925,567.391 983.333,530.435 1041.67,493.478 983.333,530.435 925,567.391 \" fill=\"none\" stroke=\"brown\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"1216.67,900 1158.33,715.217 1216.67,752.174 1275,789.13 1333.33,826.087 1391.67,863.043 1450,900 1391.67,863.043 1333.33,826.087 1275,789.13 1216.67,752.174 1158.33,715.217 1216.67,900 \" fill=\"none\" stroke=\"orange\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >13</text><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"red\" stroke=\"none\" stroke-width=\"1\" >13</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >13</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"red\" stroke=\"none\" stroke-width=\"1\" >13</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >23</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"green\" stroke=\"none\" stroke-width=\"1\" >23</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >23</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"green\" stroke=\"none\" stroke-width=\"1\" >23</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >36</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"blue\" stroke=\"none\" stroke-width=\"1\" >36</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >36</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"blue\" stroke=\"none\" stroke-width=\"1\" >36</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >44к</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"brown\" stroke=\"none\" stroke-width=\"1\" >44к</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >44к</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"brown\" stroke=\"none\" stroke-width=\"1\" >44к</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >90</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"orange\" stroke=\"none\" stroke-width=\"1\" >90</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >90</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"orange\" stroke=\"none\" stroke-width=\"1\" >90</text><circle cx=\"575\" cy=\"382.609\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"225\" cy=\"160.87\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"341.667\" cy=\"234.783\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1216.67\" cy=\"900\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"458.333\" cy=\"308.696\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1391.67\" cy=\"863.043\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1450\" cy=\"900\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"691.667\" cy=\"456.522\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"283.333\" cy=\"197.826\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"750\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"516.667\" cy=\"345.652\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"166.667\" cy=\"271.739\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"925\" cy=\"567.391\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"400\" cy=\"419.565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"925\" cy=\"456.522\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"866.667\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1333.33\" cy=\"826.087\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1100\" cy=\"678.261\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1275\" cy=\"789.13\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"225\" cy=\"308.696\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"283.333\" cy=\"345.652\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"50\" cy=\"197.826\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1216.67\" cy=\"752.174\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"108.333\" cy=\"234.783\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"633.333\" cy=\"419.565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"341.667\" cy=\"382.609\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"641.304\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"808.333\" cy=\"530.435\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1158.33\" cy=\"715.217\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"419.565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"530.435\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"400\" cy=\"271.739\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"50\" cy=\"50\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"166.667\" cy=\"123.913\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"108.333\" cy=\"86.9565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"604.348\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><text x=\"575\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Автовокзал</text><text x=\"575\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Автовокзал</text><text x=\"225\" y=\"160.87\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Деревообр. комбинат</text><text x=\"225\" y=\"160.87\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Деревообр. комбинат</text><text x=\"341.667\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Кинотеатр Юбилейный</text><text x=\"341.667\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Кинотеатр Юбилейный</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Краево-Греческая улица</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Краево-Греческая улица</text><text x=\"458.333\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Магазин Быт</text><text x=\"458.333\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Магазин Быт</text><text x=\"1391.67\" y=\"863.043\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Мацеста</text><text x=\"1391.67\" y=\"863.043\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Мацеста</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Мацестинская долина</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Мацестинская долина</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Морской вокзал</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Морской вокзал</text><text x=\"283.333\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Новая Заря</text><text x=\"283.333\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Новая Заря</text><text x=\"750\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Органный зал</text><text x=\"750\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Органный зал</text><text x=\"516.667\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Отель Звёздный</text><text x=\"516.667\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Отель Звёздный</text><text x=\"166.667\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пансионат Нева</text><text x=\"166.667\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пансионат Нева</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пансионат Светлана</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пансионат Светлана</text><text x=\"400\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Парк Ривьера</text><text x=\"400\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Парк Ривьера</text><text x=\"925\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пионерская улица, 111</text><text x=\"925\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пионерская улица, 111</text><text x=\"866.667\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Садовая</text><text x=\"866.667\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Садовая</text><text x=\"1333.33\" y=\"826.087\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Заря</text><text x=\"1333.33\" y=\"826.087\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Заря</text><text x=\"1100\" y=\"678.261\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Металлург</text><text x=\"1100\" y=\"678.261\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Металлург</text><text x=\"1275\" y=\"789.13\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Приморье</text><text x=\"1275\" y=\"789.13\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Приморье</text><text x=\"225\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Радуга</text><text x=\"225\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Радуга</text><text x=\"283.333\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Родина</text><text x=\"283.333\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Родина</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Салют</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Салют</text><text x=\"1216.67\" y=\"752.174\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий им. Ворошилова</text><text x=\"1216.67\" y=\"752.174\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий им. Ворошилова</text><text x=\"108.333\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторная улица</text><text x=\"108.333\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторная улица</text><text x=\"633.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Сбербанк</text><text x=\"633.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Сбербанк</text><text x=\"341.667\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Спортивная</text><text x=\"341.667\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Спортивная</text><text x=\"1041.67\" y=\"641.304\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Стадион</text><text x=\"1041.67\" y=\"641.304\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Стадион</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Театральная</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Театральная</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Бытха</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Бытха</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица В. Лысая Гора</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица В. Лысая Гора</text><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Лизы Чайкиной</text><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Лизы Чайкиной</text><text x=\"983.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Лысая Гора</text><text x=\"983.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Лысая Гора</text><text x=\"400\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Хлебозавод</text><text x=\"400\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Хлебозавод</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Целинная улица</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Целинная улица</text><text x=\"166.667\" y=\"123.913\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Целинная улица, 5</text><text x=\"166.667\" y=\"123.913\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Целинная улица, 5</text><text x=\"108.333\" y=\"86.9565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Целинная улица, 57</text><text x=\"108.333\" y=\"86.9565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Целинная улица, 57</text><text x=\"983.333\" y=\"604.348\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Цирк</text><text x=\"983.333\" y=\"604.348\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Цирк</text><rect x=\"-150\" y=\"-150\" width=\"1800\" height=\"1250\" fill=\"rgba(255,255,255,0.85)\" stroke=\"none\" stroke-width=\"1\" /><polyline points=\"1216.67,900 1158.33,715.217 \" fill=\"none\" stroke=\"orange\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"1158.33,715.217 1100,678.261 1041.67,641.304 983.333,604.348 925,567.391 808.333,530.435 750,493.478 \" fill=\"none\" stroke=\"green\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >90</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"orange\" stroke=\"none\" stroke-width=\"1\" >90</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >23</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"green\" stroke=\"none\" stroke-width=\"1\" >23</text><circle cx=\"1216.67\" cy=\"900\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1158.33\" cy=\"715.217\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1158.33\" cy=\"715.217\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1100\" cy=\"678.261\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"641.304\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"604.348\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"925\" cy=\"567.391\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"808.333\" cy=\"530.435\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"750\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Краево-Греческая улица</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Краево-Греческая улица</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Бытха</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Бытха</text><text x=\"750\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Органный зал</text><text x=\"750\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Органный зал</text></svg>",
    "request_id": 1142770959,
    "total_time": 16.34
  },
  {
    "items": [
      {
        "stop_name": "Краево-Греческая улица",
        "time": 2,
        "type": "WaitBus"
      },
      {
        "bus": "90",
        "span_count": 1,
        "time": 3.56,
        "type": "RideBus"
      },
      {
        "stop_name": "Улица Бытха",
        "time": 2,
        "type": "WaitBus"
      },
      {
        "bus": "23",
        "span_count": 4,
        "time": 6.46,
        "type": "RideBus"
      },
      {
        "company": "им. Фрунзе",
        "stop_name": "Пансионат Светлана",
        "time": 8.7,
        "type": "WalkToCompany"
      }
    ],
    "map": "<?xml version=\"1.0\" encoding=\"UTF-8\" ?><svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"><polyline points=\"983.333,419.565 925,456.522 866.667,493.478 808.333,530.435 866.667,493.478 925,456.522 983.333,419.565 \" fill=\"none\" stroke=\"red\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"50,197.826 108.333,234.783 166.667,271.739 225,308.696 283.333,345.652 341.667,382.609 400,419.565 691.667,456.522 750,493.478 808.333,530.435 925,567.391 983.333,604.348 1041.67,641.304 1100,678.261 1158.33,715.217 1100,678.261 1041.67,641.304 983.333,604.348 925,567.391 808.333,530.435 750,493.478 691.667,456.522 400,419.565 341.667,382.609 283.333,345.652 225,308.696 166.667,271.739 108.333,234.783 50,197.826 \" fill=\"none\" stroke=\"green\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"691.667,456.522 633.333,419.565 575,382.609 516.667,345.652 458.333,308.696 400,271.739 341.667,234.783 283.333,197.826 225,160.87 166.667,123.913 108.333,86.9565 50,50 108.333,86.9565 166.667,123.913 225,160.87 283.333,197.826 341.667,234.783 400,271.739 458.333,308.696 516.667,345.652 575,382.609 633.333,419.565 691.667,456.522 \" fill=\"none\" stroke=\"blue\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"925,567.391 983.333,530.435 1041.67,493.478 983.333,530.435 925,567.391 \" fill=\"none\" stroke=\"brown\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"1216.67,900 1158.33,715.217 1216.67,752.174 1275,789.13 1333.33,826.087 1391.67,863.043 1450,900 1391.67,863.043 1333.33,826.087 1275,789.13 1216.67,752.174 1158.33,715.217 1216.67,900 \" fill=\"none\" stroke=\"orange\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >13</text><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"red\" stroke=\"none\" stroke-width=\"1\" >13</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >13</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"red\" stroke=\"none\" stroke-width=\"1\" >13</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >23</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"green\" stroke=\"none\" stroke-width=\"1\" >23</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >23</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"green\" stroke=\"none\" stroke-width=\"1\" >23</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >36</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"blue\" stroke=\"none\" stroke-width=\"1\" >36</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >36</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"blue\" stroke=\"none\" stroke-width=\"1\" >36</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >44к</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"brown\" stroke=\"none\" stroke-width=\"1\" >44к</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >44к</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"brown\" stroke=\"none\" stroke-width=\"1\" >44к</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >90</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"orange\" stroke=\"none\" stroke-width=\"1\" >90</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >90</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"orange\" stroke=\"none\" stroke-width=\"1\" >90</text><circle cx=\"575\" cy=\"382.609\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"225\" cy=\"160.87\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"341.667\" cy=\"234.783\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1216.67\" cy=\"900\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"458.333\" cy=\"308.696\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1391.67\" cy=\"863.043\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1450\" cy=\"900\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"691.667\" cy=\"456.522\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"283.333\" cy=\"197.826\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"750\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"516.667\" cy=\"345.652\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"166.667\" cy=\"271.739\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"925\" cy=\"567.391\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"400\" cy=\"419.565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"925\" cy=\"456.522\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"866.667\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1333.33\" cy=\"826.087\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1100\" cy=\"678.261\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1275\" cy=\"789.13\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"225\" cy=\"308.696\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"283.333\" cy=\"345.652\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"50\" cy=\"197.826\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1216.67\" cy=\"752.174\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"108.333\" cy=\"234.783\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"633.333\" cy=\"419.565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"341.667\" cy=\"382.609\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"641.304\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"808.333\" cy=\"530.435\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1158.33\" cy=\"715.217\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"419.565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"530.435\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"400\" cy=\"271.739\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"50\" cy=\"50\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"166.667\" cy=\"123.913\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"108.333\" cy=\"86.9565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"604.348\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><text x=\"575\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Автовокзал</text><text x=\"575\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Автовокзал</text><text x=\"225\" y=\"160.87\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Деревообр. комбинат</text><text x=\"225\" y=\"160.87\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Деревообр. комбинат</text><text x=\"341.667\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Кинотеатр Юбилейный</text><text x=\"341.667\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Кинотеатр Юбилейный</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Краево-Греческая улица</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Краево-Греческая улица</text><text x=\"458.333\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Магазин Быт</text><text x=\"458.333\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Магазин Быт</text><text x=\"1391.67\" y=\"863.043\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Мацеста</text><text x=\"1391.67\" y=\"863.043\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Мацеста</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Мацестинская долина</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Мацестинская долина</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Морской вокзал</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Морской вокзал</text><text x=\"283.333\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Новая Заря</text><text x=\"283.333\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Новая Заря</text><text x=\"750\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Органный зал</text><text x=\"750\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Органный зал</text><text x=\"516.667\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Отель Звёздный</text><text x=\"516.667\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Отель Звёздный</text><text x=\"166.667\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пансионат Нева</text><text x=\"166.667\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пансионат Нева</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пансионат Светлана</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пансионат Светлана</text><text x=\"400\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Парк Ривьера</text><text x=\"400\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Парк Ривьера</text><text x=\"925\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пионерская улица, 111</text><text x=\"925\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пионерская улица, 111</text><text x=\"866.667\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Садовая</text><text x=\"866.667\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Садовая</text><text x=\"1333.33\" y=\"826.087\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Заря</text><text x=\"1333.33\" y=\"826.087\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Заря</text><text x=\"1100\" y=\"678.261\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Металлург</text><text x=\"1100\" y=\"678.261\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Металлург</text><text x=\"1275\" y=\"789.13\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Приморье</text><text x=\"1275\" y=\"789.13\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Приморье</text><text x=\"225\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Радуга</text><text x=\"225\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Радуга</text><text x=\"283.333\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Родина</text><text x=\"283.333\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Родина</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Салют</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Салют</text><text x=\"1216.67\" y=\"752.174\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий им. Ворошилова</text><text x=\"1216.67\" y=\"752.174\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий им. Ворошилова</text><text x=\"108.333\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторная улица</text><text x=\"108.333\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторная улица</text><text x=\"633.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Сбербанк</text><text x=\"633.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Сбербанк</text><text x=\"341.667\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Спортивная</text><text x=\"341.667\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Спортивная</text><text x=\"1041.67\" y=\"641.304\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Стадион</text><text x=\"1041.67\" y=\"641.304\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Стадион</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Театральная</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Театральная</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Бытха</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Бытха</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица В. Лысая Гора</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица В. Лысая Гора</text><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Лизы Чайкиной</text><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Лизы Чайкиной</text><text x=\"983.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Лысая Гора</text><text x=\"983.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Лысая Гора</text><text x=\"400\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Хлебозавод</text><text x=\"400\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Хлебозавод</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Целинная улица</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Целинная улица</text><text x=\"166.667\" y=\"123.913\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Целинная улица, 5</text><text x=\"166.667\" y=\"123.913\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Целинная улица, 5</text><text x=\"108.333\" y=\"86.9565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Целинная улица, 57</text><text x=\"108.333\" y=\"86.9565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Целинная улица, 57</text><text x=\"983.333\" y=\"604.348\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Цирк</text><text x=\"983.333\" y=\"604.348\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Цирк</text><rect x=\"-150\" y=\"-150\" width=\"1800\" height=\"1250\" fill=\"rgba(255,255,255,0.85)\" stroke=\"none\" stroke-width=\"1\" /><polyline points=\"1216.67,900 1158.33,715.217 \" fill=\"none\" stroke=\"orange\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"1158.33,715.217 1100,678.261 1041.67,641.304 983.333,604.348 925,567.391 \" fill=\"none\" stroke=\"green\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"925,567.391 866.667,900 \" fill=\"none\" stroke=\"black\" stroke-width=\"2\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >90</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"orange\" stroke=\"none\" stroke-width=\"1\" >90</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >23</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"green\" stroke=\"none\" stroke-width=\"1\" >23</text><circle cx=\"1216.67\" cy=\"900\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1158.33\" cy=\"715.217\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1158.33\" cy=\"715.217\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1100\" cy=\"678.261\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"641.304\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"604.348\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"925\" cy=\"567.391\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"866.667\" cy=\"900\" r=\"5\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" /><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Краево-Греческая улица</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Краево-Греческая улица</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Бытха</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Бытха</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пансионат Светлана</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пансионат Светлана</text><text x=\"866.667\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Парк им. Фрунзе</text><text x=\"866.667\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Парк им. Фрунзе</text></svg>",
    "request_id": 940120142,
    "total_time": 22.72
  },
  {
    "items": [
      {
        "stop_name": "Краево-Греческая улица",
        "time": 2,
        "type": "WaitBus"
      },
      {
        "bus": "90",
        "span_count": 1,
        "time": 3.56,
        "type": "RideBus"
      },
      {
        "stop_name": "Улица Бытха",
        "time": 2,
        "type": "WaitBus"
      },
      {
        "bus": "23",
        "span_count": 3,
        "time": 5.42,
        "type": "RideBus"
      },
      {
        "company": "Дендрарий",
        "stop_name": "Цирк",
        "time": 2.7,
        "type": "WalkToCompany"
      },
      {
        "company": "Дендрарий",
        "time": 4.32,
        "type": "WaitCompany"
      }
    ],
    "map": "<?xml version=\"1.0\" encoding=\"UTF-8\" ?><svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"><polyline points=\"983.333,419.565 925,456.522 866.667,493.478 808.333,530.435 866.667,493.478 925,456.522 983.333,419.565 \" fill=\"none\" stroke=\"red\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"50,197.826 108.333,234.783 166.667,271.739 225,308.696 283.333,345.652 341.667,382.609 400,419.565 691.667,456.522 750,493.478 808.333,530.435 925,567.391 983.333,604.348 1041.67,641.304 1100,678.261 1158.33,715.217 1100,678.261 1041.67,641.304 983.333,604.348 925,567.391 808.333,530.435 750,493.478 691.667,456.522 400,419.565 341.667,382.609 283.333,345.652 225,308.696 166.667,271.739 108.333,234.783 50,197.826 \" fill=\"none\" stroke=\"green\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"691.667,456.522 633.333,419.565 575,382.609 516.667,345.652 458.333,308.696 400,271.739 341.667,234.783 283.333,197.826 225,160.87 166.667,123.913 108.333,86.9565 50,50 108.333,86.9565 166.667,123.913 225,160.87 283.333,197.826 341.667,234.783 400,271.739 458.333,308.696 516.667,345.652 575,382.609 633.333,419.565 691.667,456.522 \" fill=\"none\" stroke=\"blue\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"925,567.391 983.333,530.435 1041.67,493.478 983.333,530.435 925,567.391 \" fill=\"none\" stroke=\"brown\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"1216.67,900 1158.33,715.217 1216.67,752.174 1275,789.13 1333.33,826.087 1391.67,863.043 1450,900 1391.67,863.043 1333.33,826.087 1275,789.13 1216.67,752.174 1158.33,715.217 1216.67,900 \" fill=\"none\" stroke=\"orange\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >13</text><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"red\" stroke=\"none\" stroke-width=\"1\" >13</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >13</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"red\" stroke=\"none\" stroke-width=\"1\" >13</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >23</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"green\" stroke=\"none\" stroke-width=\"1\" >23</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >23</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"green\" stroke=\"none\" stroke-width=\"1\" >23</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >36</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"blue\" stroke=\"none\" stroke-width=\"1\" >36</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >36</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"blue\" stroke=\"none\" stroke-width=\"1\" >36</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >44к</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"brown\" stroke=\"none\" stroke-width=\"1\" >44к</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >44к</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"brown\" stroke=\"none\" stroke-width=\"1\" >44к</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >90</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"orange\" stroke=\"none\" stroke-width=\"1\" >90</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >90</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"orange\" stroke=\"none\" stroke-width=\"1\" >90</text><circle cx=\"575\" cy=\"382.609\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"225\" cy=\"160.87\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"341.667\" cy=\"234.783\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1216.67\" cy=\"900\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"458.333\" cy=\"308.696\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1391.67\" cy=\"863.043\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1450\" cy=\"900\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"691.667\" cy=\"456.522\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"283.333\" cy=\"197.826\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"750\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"516.667\" cy=\"345.652\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"166.667\" cy=\"271.739\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"925\" cy=\"567.391\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"400\" cy=\"419.565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"925\" cy=\"456.522\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"866.667\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1333.33\" cy=\"826.087\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1100\" cy=\"678.261\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1275\" cy=\"789.13\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"225\" cy=\"308.696\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"283.333\" cy=\"345.652\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"50\" cy=\"197.826\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1216.67\" cy=\"752.174\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"108.333\" cy=\"234.783\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"633.333\" cy=\"419.565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"341.667\" cy=\"382.609\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"641.304\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"808.333\" cy=\"530.435\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1158.33\" cy=\"715.217\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"493.478\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"419.565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"530.435\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"400\" cy=\"271.739\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"50\" cy=\"50\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"166.667\" cy=\"123.913\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"108.333\" cy=\"86.9565\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"604.348\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><text x=\"575\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Автовокзал</text><text x=\"575\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Автовокзал</text><text x=\"225\" y=\"160.87\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Деревообр. комбинат</text><text x=\"225\" y=\"160.87\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Деревообр. комбинат</text><text x=\"341.667\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Кинотеатр Юбилейный</text><text x=\"341.667\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Кинотеатр Юбилейный</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Краево-Греческая улица</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Краево-Греческая улица</text><text x=\"458.333\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Магазин Быт</text><text x=\"458.333\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Магазин Быт</text><text x=\"1391.67\" y=\"863.043\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Мацеста</text><text x=\"1391.67\" y=\"863.043\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Мацеста</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Мацестинская долина</text><text x=\"1450\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Мацестинская долина</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Морской вокзал</text><text x=\"691.667\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Морской вокзал</text><text x=\"283.333\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Новая Заря</text><text x=\"283.333\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Новая Заря</text><text x=\"750\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Органный зал</text><text x=\"750\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Органный зал</text><text x=\"516.667\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Отель Звёздный</text><text x=\"516.667\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Отель Звёздный</text><text x=\"166.667\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пансионат Нева</text><text x=\"166.667\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пансионат Нева</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пансионат Светлана</text><text x=\"925\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пансионат Светлана</text><text x=\"400\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Парк Ривьера</text><text x=\"400\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Парк Ривьера</text><text x=\"925\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Пионерская улица, 111</text><text x=\"925\" y=\"456.522\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Пионерская улица, 111</text><text x=\"866.667\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Садовая</text><text x=\"866.667\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Садовая</text><text x=\"1333.33\" y=\"826.087\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Заря</text><text x=\"1333.33\" y=\"826.087\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Заря</text><text x=\"1100\" y=\"678.261\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Металлург</text><text x=\"1100\" y=\"678.261\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Металлург</text><text x=\"1275\" y=\"789.13\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Приморье</text><text x=\"1275\" y=\"789.13\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Приморье</text><text x=\"225\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Радуга</text><text x=\"225\" y=\"308.696\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Радуга</text><text x=\"283.333\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Родина</text><text x=\"283.333\" y=\"345.652\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Родина</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий Салют</text><text x=\"50\" y=\"197.826\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий Салют</text><text x=\"1216.67\" y=\"752.174\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторий им. Ворошилова</text><text x=\"1216.67\" y=\"752.174\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторий им. Ворошилова</text><text x=\"108.333\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Санаторная улица</text><text x=\"108.333\" y=\"234.783\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Санаторная улица</text><text x=\"633.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Сбербанк</text><text x=\"633.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Сбербанк</text><text x=\"341.667\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Спортивная</text><text x=\"341.667\" y=\"382.609\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Спортивная</text><text x=\"1041.67\" y=\"641.304\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Стадион</text><text x=\"1041.67\" y=\"641.304\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Стадион</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Театральная</text><text x=\"808.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Театральная</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Бытха</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Бытха</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица В. Лысая Гора</text><text x=\"1041.67\" y=\"493.478\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица В. Лысая Гора</text><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Лизы Чайкиной</text><text x=\"983.333\" y=\"419.565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Лизы Чайкиной</text><text x=\"983.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Лысая Гора</text><text x=\"983.333\" y=\"530.435\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Лысая Гора</text><text x=\"400\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Хлебозавод</text><text x=\"400\" y=\"271.739\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Хлебозавод</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Целинная улица</text><text x=\"50\" y=\"50\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Целинная улица</text><text x=\"166.667\" y=\"123.913\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Целинная улица, 5</text><text x=\"166.667\" y=\"123.913\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Целинная улица, 5</text><text x=\"108.333\" y=\"86.9565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Целинная улица, 57</text><text x=\"108.333\" y=\"86.9565\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Целинная улица, 57</text><text x=\"983.333\" y=\"604.348\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Цирк</text><text x=\"983.333\" y=\"604.348\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Цирк</text><rect x=\"-150\" y=\"-150\" width=\"1800\" height=\"1250\" fill=\"rgba(255,255,255,0.85)\" stroke=\"none\" stroke-width=\"1\" /><polyline points=\"1216.67,900 1158.33,715.217 \" fill=\"none\" stroke=\"orange\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"1158.33,715.217 1100,678.261 1041.67,641.304 983.333,604.348 \" fill=\"none\" stroke=\"green\" stroke-width=\"10\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><polyline points=\"983.333,604.348 1041.67,567.391 \" fill=\"none\" stroke=\"black\" stroke-width=\"2\" stroke-linecap=\"round\" stroke-linejoin=\"round\" /><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >90</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"orange\" stroke=\"none\" stroke-width=\"1\" >90</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >23</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"15\" font-size=\"18\" font-family=\"Verdana\" font-weight=\"bold\" fill=\"green\" stroke=\"none\" stroke-width=\"1\" >23</text><circle cx=\"1216.67\" cy=\"900\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1158.33\" cy=\"715.217\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1158.33\" cy=\"715.217\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1100\" cy=\"678.261\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"641.304\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"983.333\" cy=\"604.348\" r=\"3\" fill=\"white\" stroke=\"none\" stroke-width=\"1\" /><circle cx=\"1041.67\" cy=\"567.391\" r=\"5\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" /><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Краево-Греческая улица</text><text x=\"1216.67\" y=\"900\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Краево-Греческая улица</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Улица Бытха</text><text x=\"1158.33\" y=\"715.217\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Улица Бытха</text><text x=\"983.333\" y=\"604.348\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Цирк</text><text x=\"983.333\" y=\"604.348\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Цирк</text><text x=\"1041.67\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" >Парк Дендрарий</text><text x=\"1041.67\" y=\"567.391\" dx=\"7\" dy=\"-3\" font-size=\"13\" font-family=\"Verdana\" fill=\"black\" stroke=\"none\" stroke-width=\"1\" >Парк Дендрарий</text></svg>",
    "request_id": 1054152420,
    "total_time": 20
  }
]
```


