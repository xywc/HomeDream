#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <math.h>
using namespace std;

enum ConstrcutionType {industrial,commercial,residential}; //声明枚举类型
enum Quality {common,rare,epic};
enum Unit {M,B,T,a,b,c,d,e,f};
enum Object{
    //商业建筑
    convenience_store = 1,
    school = 2,
    clothing_store = 3,
    hardware_store = 4,
    food_market = 5,
    book_shop = 6,
    trade_center = 7,
    petrol_station = 8,
    folk_food = 9,
    media_voice = 10,
    natatorium = 11,
    dream_express = 12,

    //住宅建筑
    wooden_house = 101,
    steel_house = 102,
    bungalow = 103,
    studio_apartment = 104,
    residential_buildings = 105,
    talent_apartment = 106,
    garden_house = 107,
    chinese_building = 108,
    air_villa = 109,
    renaissance_mansion = 110,
    dream_apartment = 111,

    //工业建筑
    power_plant = 201,
    wood_factory = 202,
    paper_mill = 203,
    water_plant = 204,
    food_manufacturer = 205,
    steel_plant = 206,
    people_petroleum = 207,
    textile_mill = 208,
    parts_factory = 209,
    penguin_machinery = 210,
    coal_plant = 211,

    all = -1,
    online = -2,
    offline = -3,
    commercial_building = -4,
    industrial_building = -5,
    residential_building = -6,
    supply_commodity = -7
};
typedef pair<Object,float>  Attribute;
struct Construction{
    int id;
    int grade;
    ConstrcutionType type;
    Quality quality;
    int star;
    pair<float,Unit> income;
    int income_interval;
    vector<Attribute> attribute;
    string name;
};
static map<int,float>city_mission={{1,2.0f},{10,1.0f},{5,1.0f}};
static float home_light=0.35f;
static Unit unit = c;
static vector<Construction> residential_constructions={
    {101,1300,residential,common,5,{4.19,b},1,{{wood_factory,5.0f}},"木屋"},
    {102,1300,residential,common,5,{4.19,b},1,{{steel_plant,5.0f}},"钢结构房"},
    {103,1300,residential,common,5,{4.61,b},15,{{residential_building,1.0f}},"平房"},
    {104,1300,residential,common,5,{4.95,b},15,{{supply_commodity,70.0f}},"小型公寓"},
    {105,1300,residential,common,5,{4.19,b},10,{{convenience_store,5.0f}},"居民楼"},
    {106,1300,residential,rare,5,{5.87,b},15,{{industrial_building,0.75f},{online,1.0f}},"人才公寓"},
    {107,1300,residential,rare,5,{4.28,b},10,{{trade_center,5.0f},{supply_commodity,50.0f}},"花园洋房"},
    {108,1300,residential,rare,5,{5.87,b},15,{{online,1.0f},{residential_building,0.75f}},"中式小楼"},
    {109,1400,residential,epic,4,{29.3,b},1,{{online,0.8f},{folk_food,4.0f}},"空中别墅"},
    {110,1400,residential,epic,4,{32.3,b},10,{{offline,0.4f},{supply_commodity,40.0f}},"复兴公馆"},
    {111,0,residential,epic,0,{0,b},5,{{natatorium,0.0f},{coal_plant,0.0f}},"梦想公寓"},
};

static vector<Construction> commercial_constructions={
    {1,1300,commercial,common,5,{4.19,b},5,{{residential_buildings,5.0f}},"便利店"},
    {2,1300,commercial,common,5,{4.19,b},25,{{book_shop,5.0f}},"学校"},
    {3,1300,commercial,common,5,{4.19,b},25,{{textile_mill,5.0f}},"服装店"},
    {4,1300,commercial,common,5,{4.19,b},15,{{parts_factory,5.0f}},"五金店"},
    {5,1300,commercial,common,5,{4.19,b},5,{{food_manufacturer,5.0f}},"菜市场"},
    {6,1300,commercial,rare,5,{4.19,b},15,{{paper_mill,5.0f},{school,5.0f}},"图书城"},
    {7,1397,commercial,rare,5,{90.7,b},5,{{garden_house,5.0f},{supply_commodity,50.0f}},"商贸中心"},
    {8,1300,commercial,rare,5,{5.05,b},25,{{people_petroleum,2.5f},{offline,0.5f}},"加油站"},
    {9,1400,commercial,epic,4,{29.3,b},5,{{air_villa,4.0f},{online,0.8f}},"民食斋"},
    {10,1300,commercial,epic,4,{1.35,b},15,{{offline,0.4f},{all,0.20f}},"媒体之声"},
    {11,0,commercial,epic,0,{0,b},1,{{dream_apartment,0.0f},{commercial_building,0.0f}},"游泳馆"},
    {12,0,commercial,rare,0,{0,b},1,{{commercial_building,0.0f},{supply_commodity,0.0f}},"追梦快递"},
};

static vector<Construction> industrial_constructions={
    {201,1300,industrial,common,5,{4.95,b},35,{{online,1.4f}},"电厂"},
    {202,1300,industrial,common,5,{4.19,b},15,{{wooden_house,5.0f}},"木材厂"},
    {203,1300,industrial,common,5,{4.19,b},35,{{book_shop,5.0f}},"造纸厂"},
    {204,1300,industrial,common,5,{5.28,b},35,{{offline,0.3f}},"水厂"},
    {205,1301,industrial,common,5,{4.35,b},25,{{food_market,5.0f}},"食品厂"},
    {206,1300,industrial,rare,5,{4.19,b},15,{{steel_house,5.0f},{industrial_building,0.75f}},"钢铁厂"},
    {207,1300,industrial,epic,4,{839,a},15,{{petrol_station,4.0f},{offline,0.4f}},"人民石油"},
    {208,1300,industrial,rare,5,{4.19,b},35,{{clothing_store,5.0f},{commercial_building,0.75f}},"纺织厂"},
    {209,1300,industrial,rare,5,{4.19,b},25,{{hardware_store,5.0f},{penguin_machinery,2.5f}},"零件厂"},
    {210,1300,industrial,epic,4,{1.11,b},25,{{parts_factory,4.0f},{all,0.4f}},"企鹅机械"},
    {211,0,industrial,epic,0,{0,b},1,{{dream_apartment,0.0f},{industrial_building,0.0f}},"强国煤业"}
};

static vector<pair<string,Attribute>> policy_center={
    {"一带一路建设",{all,1.0f}},{"自由贸易区建设",{commercial_building,3.0f}},{"区域协调发展",{residential_building,3.0f}},

    {"全面深化改革",{all,2.0f}},{"全面依法治国",{online,2.0f}},{"科教兴国",{offline,2.0f}},{"创新驱动",{industrial_building,6.0f}},

    {"制造强国",{industrial_building,12.0f}},{"优化营商环境",{supply_commodity,30.0f}},{"减税降费",{all,4.0f}},{"普惠金融",{commercial_building,12.0f}},

    {"新型城镇化",{residential_building,24.0f}},{"乡村振兴",{online,8.0f}},{"精准扶贫",{offline,8.0f}},{"新一代人工智能",{all,8.0f}},

    {"医保异地结算",{industrial_building,36.0f}},{"大病保险",{offline,12.0f}},{"幼有所育",{residential_building,27.0f}},
    {"老有所养",{commercial_building,36.0f}},{"全面二孩",{all,12.0f}},
};

static float all_addition=4.3f;
static float supply_addition=58.0f;
static float online_addition=4.1f;
static float offline_addition=4.1f;
static float residential_addtion=6.6f;
static float commercial_addition=7.5f;
static float industrial_addition=8.7f;

static map<int,Construction> allconstructions;
void HashConstruction()
{
    allconstructions.clear();
    for(auto item : residential_constructions)
    {
        allconstructions.insert({item.id,item});
    }
    for(auto item : commercial_constructions)
    {
        allconstructions.insert({item.id,item});
    }
    for(auto item : industrial_constructions)
    {
        allconstructions.insert({item.id,item});
    }
}

vector<tuple<size_t,size_t,size_t>> SelectConstruction(vector<Construction> constructions)
{
    vector<tuple<size_t,size_t,size_t>>result;
    result.reserve(800);
    size_t n =constructions.size();
    for(size_t i=0;i<n;++i)
    {
        for(size_t j=i+1;j<n;++j)
        {
            for(size_t k=j+1;k<n;++k)
            {
                result.push_back({i,j,k});
            }
        }
    }
    return result;
}

float ConvertUint(pair<float,char> income)
{
    return income.first*pow(10,3*(income.second-unit));
}

static float all_policy_addition=0.0f;
static float online_policy_addition=0.0f;
static float offline_policy_addition=0.0f;
static float commercial_policy_addition=0.0f;
static float industrial_policy_addition=0.0f;
static float residential_policy_addtion=0.0f;
static float supply_policy_addition=0.0f;

tuple<float,float,float> ComputeIncome(map<int,pair<float,float>> &all_current_construction)
{
    float online_income = 0.0f;
    float offline_income = 0.0f;
    float supply = 0.0f;

    map<int,float> current_addition;
    float current_construction_addition_online=0.0f;
    float current_construction_addition_offline=0.0f;
    float city_mission_addition_online=0.0f;
    float city_mission_addition_offline=0.0f;
    float china_travelogues_addition_online=0.0f;
    float china_travelogues_addition_offline=0.0f;
    float policy_center_addition_online=0.0f;
    float policy_center_addition_offline=0.0f;

    for(auto i : all_current_construction)
    {
        vector<Attribute> attribute = allconstructions[i.first].attribute;
        for(auto attr : attribute)
        {
            if(current_addition.count(attr.first)>0)
                current_addition[attr.first] += attr.second;
            else {
                current_addition.insert({attr.first,attr.second});
            }
            if(attr.first == supply_commodity)
            {
                supply += attr.second;
            }
        }
    }
    for(auto i=all_current_construction.begin();i!=all_current_construction.end();++i)
    {
        current_construction_addition_online=0.0f;
        current_construction_addition_offline=0.0f;
        city_mission_addition_online=0.0f;
        city_mission_addition_offline=0.0f;
        china_travelogues_addition_online=0.0f;
        china_travelogues_addition_offline=0.0f;
        policy_center_addition_online=0.0f;
        policy_center_addition_offline=0.0f;
        int id = i->first;
        i->second.first = ConvertUint(allconstructions[id].income);
        i->second.second = ConvertUint(allconstructions[id].income);
        switch (allconstructions[id].type) {
        case industrial:
            if(city_mission.find(-5)!=city_mission.end())
            {
                city_mission_addition_online +=city_mission.find(-5)->second;
                city_mission_addition_offline +=city_mission.find(-5)->second;
            }

            if(current_addition.find(-5)!=current_addition.end())
            {
                current_construction_addition_online +=current_addition.find(-5)->second;
                current_construction_addition_offline +=current_addition.find(-5)->second;
            }

            policy_center_addition_online += all_policy_addition+industrial_policy_addition+online_policy_addition+home_light;
            china_travelogues_addition_online += all_addition+industrial_addition+online_addition;

            policy_center_addition_offline += all_policy_addition+industrial_policy_addition+offline_policy_addition+home_light;
            china_travelogues_addition_offline += all_addition+industrial_addition+offline_addition;
            break;
        case commercial:
            if(city_mission.find(-4)!=city_mission.end())
            {
                city_mission_addition_online +=city_mission.find(-4)->second;
                city_mission_addition_offline +=city_mission.find(-4)->second;
            }

            if(current_addition.find(-4)!=current_addition.end())
            {
                current_construction_addition_online +=current_addition.find(-4)->second;
                current_construction_addition_offline +=current_addition.find(-4)->second;
            }

            policy_center_addition_online += all_policy_addition+commercial_policy_addition+online_policy_addition+home_light;
            china_travelogues_addition_online += all_addition+commercial_addition+online_addition;

            policy_center_addition_offline += all_policy_addition+commercial_policy_addition+offline_policy_addition+home_light;
            china_travelogues_addition_offline += all_addition+commercial_addition+offline_addition;
            break;
        case residential:
            if(city_mission.find(-6)!=city_mission.end())
            {
                city_mission_addition_online +=city_mission.find(-6)->second;
                city_mission_addition_offline +=city_mission.find(-6)->second;
            }

            if(current_addition.find(-6)!=current_addition.end())
            {
                current_construction_addition_online +=current_addition.find(-6)->second;
                current_construction_addition_offline +=current_addition.find(-6)->second;
            }

            policy_center_addition_online += all_policy_addition+residential_policy_addtion+online_policy_addition+home_light;
            china_travelogues_addition_online += all_addition+residential_addtion+online_addition;

            policy_center_addition_offline += all_policy_addition+residential_policy_addtion+offline_policy_addition+home_light;
            china_travelogues_addition_offline += all_addition+residential_addtion+offline_addition;
            break;
        }

        if(city_mission.find(id)!=city_mission.end())
        {
            city_mission_addition_online +=city_mission.find(id)->second;
            city_mission_addition_offline +=city_mission.find(id)->second;
        }
        if(city_mission.find(-2)!=city_mission.end())
        {
            city_mission_addition_online +=city_mission.find(-2)->second;
        }
        if(city_mission.find(-3)!=city_mission.end())
        {
            city_mission_addition_offline +=city_mission.find(-3)->second;
        }
        if(city_mission.find(-1)!=city_mission.end())
        {
            city_mission_addition_online +=city_mission.find(-1)->second;
            city_mission_addition_offline +=city_mission.find(-1)->second;
        }

        if(current_addition.find(id)!=current_addition.end())
        {
            current_construction_addition_online +=current_addition.find(id)->second;
            current_construction_addition_offline +=current_addition.find(id)->second;
        }
        if(current_addition.find(-2)!=current_addition.end())
        {
            current_construction_addition_online +=current_addition.find(-2)->second;
        }
        if(current_addition.find(-3)!=current_addition.end())
        {
            current_construction_addition_offline +=current_addition.find(-3)->second;
        }
        if(current_addition.find(-1)!=current_addition.end())
        {
            current_construction_addition_online +=current_addition.find(-1)->second;
            current_construction_addition_offline +=current_addition.find(-1)->second;
        }


        i->second.first *= 1+current_construction_addition_online;
        i->second.second *= 1+current_construction_addition_offline;

        i->second.first *= 1+policy_center_addition_online;
        i->second.second *= 1+policy_center_addition_offline;

        i->second.first *= 1+china_travelogues_addition_online;
        i->second.second *= 1+china_travelogues_addition_offline;

        i->second.first *= 1+city_mission_addition_online;
        i->second.second *= 1+city_mission_addition_offline;

        i->second.second *= 0.5f;
    }
    if(city_mission.find(-7)!=city_mission.end())
    {
        supply +=city_mission.find(-7)->second;
    }
    for(auto i : all_current_construction)
    {
        online_income += i.second.first;
        offline_income += i.second.second;
    }
    supply +=supply_addition+supply_policy_addition;
    return {online_income,offline_income,supply};
}

void PrintResult(map<int,pair<float,float>> all_current_construction)
{
    int i=0;
    for(auto id : all_current_construction)
    {
        if(i==0)cout<<"商业建筑："<<endl;
        if(i==3)cout<<"住宅建筑："<<endl;
        if(i==6)cout<<"工业建筑："<<endl;
        cout<<"   "<<allconstructions[id.first].name<<" "<<endl;
        i++;
    }
}

void OptimizeConstruction(vector<tuple<size_t,size_t,size_t>> commercial_set,
                            vector<tuple<size_t,size_t,size_t>> industrial_set,
                            vector<tuple<size_t,size_t,size_t>> residential_set,
                            map<int,pair<float,float>> &max_online_construction,map<int,pair<float,float>> &max_offline_construction,
                            map<int,pair<float,float>> &max_supply_construction,float &online_income,float &offline_income,float &supply)
{
    map<int,pair<float,float>> all_current_construction;
    float current_supply_online_income = 0.0f;

    for(size_t i=0;i<commercial_set.size();++i)
    {
        for(size_t j=0;j<industrial_set.size();++j)
        {
            for(size_t k=0;k<residential_set.size();++k)
            {
                all_current_construction.clear();

                all_current_construction.insert({commercial_constructions[get<0>(commercial_set[i])].id,{0.0f,0.0f}});
                all_current_construction.insert({commercial_constructions[get<1>(commercial_set[i])].id,{0.0f,0.0f}});
                all_current_construction.insert({commercial_constructions[get<2>(commercial_set[i])].id,{0.0f,0.0f}});

                all_current_construction.insert({industrial_constructions[get<0>(industrial_set[j])].id,{0.0f,0.0f}});
                all_current_construction.insert({industrial_constructions[get<1>(industrial_set[j])].id,{0.0f,0.0f}});
                all_current_construction.insert({industrial_constructions[get<2>(industrial_set[j])].id,{0.0f,0.0f}});

                all_current_construction.insert({residential_constructions[get<0>(residential_set[k])].id,{0.0f,0.0f}});
                all_current_construction.insert({residential_constructions[get<1>(residential_set[k])].id,{0.0f,0.0f}});
                all_current_construction.insert({residential_constructions[get<2>(residential_set[k])].id,{0.0f,0.0f}});

                tuple<float,float,float> income = ComputeIncome(all_current_construction);
                float current_online_income = get<0>(income);
                float current_offline_income = get<1>(income);
                float current_supply = get<2>(income);
                if(current_supply > supply)
                {
                    supply = current_supply;
                    current_supply_online_income = current_online_income;
                    max_supply_construction = all_current_construction;
                }
                if(abs(current_supply-supply)<0.001f)
                {
                    if(current_online_income > current_supply_online_income)
                    {
                        current_supply_online_income = current_online_income;
                        max_supply_construction = all_current_construction;
                    }
                }

                if(current_online_income > online_income)
                {
                    online_income = current_online_income;
                    max_online_construction = all_current_construction;
                }

                if(current_offline_income > offline_income)
                {
                    offline_income = current_offline_income;
                    max_offline_construction = all_current_construction;
                }
            }
        }
    }
}

void ComputePolicyAddition(float &all_addition,float &online_addition,float &offline_addition,
                    float &commercial_addition,float &industrial_addition,
                    float &residential_addtion,float &supply_addition)
{
    for(auto it : policy_center)
    {
        Attribute attribute = it.second;
        switch (attribute.first) {
        case -1:
            all_addition += (0.0f+attribute.second);
            break;
        case -2:
            online_addition += (0.0f+attribute.second);
            break;
        case -3:
            offline_addition += (0.0f+attribute.second);
            break;
        case -4:
            commercial_addition += (0.0f+attribute.second);
            break;
        case -5:
            industrial_addition += (0.0f+attribute.second);
            break;
        case -6:
            residential_addtion += (0.0f+attribute.second);
            break;
        case -7:
            supply_addition += attribute.second;
            break;
        default:
            cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            break;
        }
    }
}

void PrintResult(tuple<float,float,float> income)
{
    switch (unit) {
    case M:
        cout<<"在线总收入："<<get<0>(income)<<" M"<<endl;
        cout<<"离线总收入："<<get<1>(income)<<" M"<<endl;
        break;
    case B:
        cout<<"在线总收入："<<get<0>(income)<<" B"<<endl;
        cout<<"离线总收入："<<get<1>(income)<<" B"<<endl;
        break;
    case T:
        cout<<"在线总收入："<<get<0>(income)<<" T"<<endl;
        cout<<"离线总收入："<<get<1>(income)<<" T"<<endl;
        break;
    case a:
        cout<<"在线总收入："<<get<0>(income)<<" aa"<<endl;
        cout<<"离线总收入："<<get<1>(income)<<" aa"<<endl;
        break;
    case b:
        cout<<"在线总收入："<<get<0>(income)<<" bb"<<endl;
        cout<<"离线总收入："<<get<1>(income)<<" bb"<<endl;
        break;
    case c:
        cout<<"在线总收入："<<get<0>(income)<<" cc"<<endl;
        cout<<"离线总收入："<<get<1>(income)<<" cc"<<endl;
        break;
    }
    cout<<"供货的奖励增加"<<" "<<get<2>(income)<<"%"<<endl;
}

int main()
{
    HashConstruction();
    cout<<"-------家国之光加成--------"<<endl;
    cout<<"所有建筑："<<all_addition<<endl;
    cout<<"在线所有建筑："<<online_addition<<endl;
    cout<<"离线所有建筑："<<offline_addition<<endl;
    cout<<"商业建筑："<<commercial_addition<<endl;
    cout<<"工业建筑："<<industrial_addition<<endl;
    cout<<"住宅建筑："<<residential_addtion<<endl;
    cout<<"供货："<<supply_addition<<endl;

    ComputePolicyAddition(all_policy_addition,online_policy_addition,offline_policy_addition,commercial_policy_addition,industrial_policy_addition,residential_policy_addtion,supply_policy_addition);
    cout<<"-------政策中心加成--------"<<endl;
    cout<<"所有建筑："<<all_policy_addition<<endl;
    cout<<"在线所有建筑："<<online_policy_addition<<endl;
    cout<<"离线所有建筑："<<offline_policy_addition<<endl;
    cout<<"商业建筑："<<commercial_policy_addition<<endl;
    cout<<"工业建筑："<<industrial_policy_addition<<endl;
    cout<<"住宅建筑："<<residential_policy_addtion<<endl;
    cout<<"供货："<<supply_policy_addition<<endl;

    vector<tuple<size_t,size_t,size_t>> commercial_set = SelectConstruction(commercial_constructions);
    vector<tuple<size_t,size_t,size_t>> industrial_set = SelectConstruction(industrial_constructions);
    vector<tuple<size_t,size_t,size_t>> residential_set = SelectConstruction(residential_constructions);

    map<int,pair<float,float>> all_current_construction;
    all_current_construction.insert({106,{0.0f,0.0f}});
    all_current_construction.insert({107,{0.0f,0.0f}});
    all_current_construction.insert({108,{0.0f,0.0f}});

    all_current_construction.insert({2,{0.0f,0.0f}});
    all_current_construction.insert({6,{0.0f,0.0f}});
    all_current_construction.insert({7,{0.0f,0.0f}});

    all_current_construction.insert({210,{0.0f,0.0f}});
    all_current_construction.insert({203,{0.0f,0.0f}});
    all_current_construction.insert({201,{0.0f,0.0f}});


    tuple<float,float,float> income = ComputeIncome(all_current_construction);
    PrintResult(income);

    map<int,pair<float,float>> max_online_construction;
    map<int,pair<float,float>> max_offline_construction;
    map<int,pair<float,float>> max_supply_construction;
    float online_income=0.0f;
    float offline_income=0.0f;
    float supply=0.0f;
    OptimizeConstruction(commercial_set,industrial_set,residential_set,max_online_construction,
                         max_offline_construction,max_supply_construction,online_income,offline_income,supply);

    tuple<float,float,float> onlineincome = ComputeIncome(max_online_construction);
    cout<<endl;
    cout<<"-------最大在线收入--------"<<endl;
    PrintResult(max_online_construction);
    PrintResult(onlineincome);


    tuple<float,float,float> offlineincome = ComputeIncome(max_offline_construction);
    cout<<endl;
    cout<<"-------最大离线收入--------"<<endl;
    PrintResult(max_offline_construction);
    PrintResult(offlineincome);

    tuple<float,float,float> supplyincome = ComputeIncome(max_supply_construction);
    cout<<endl;
    cout<<"-------最大供货奖励--------"<<endl;
    PrintResult(max_supply_construction);
    PrintResult(supplyincome);

    return 0;
}


