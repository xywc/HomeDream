#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <map>
#include <math.h>
using namespace std;

enum ConstrcutionType {industrial,commercial,residential}; //����ö������
enum Quality {common,rare,epic};
enum Unit {M,B,T,a,b,c,d};

enum Object{
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

    wooden_house = 11,
    steel_house = 12,
    bungalow = 13,
    studio_apartment = 14,
    residential_buildings = 15,
    talent_apartment = 16,
    garden_house = 17,
    chinese_building = 18,
    air_villa = 19,
    renaissance_mansion = 20,

    power_plant = 21,
    wood_factory = 22,
    paper_mill = 23,
    water_plant = 24,
    food_manufacturer = 25,
    steel_plant = 26,
    people_petroleum = 27,
    textile_mill = 28,
    parts_factory = 29,
    penguin_machinery = 30,

    all = 31,
    online = 32,
    offline = 33,
    commercial_building = 34,
    industrial_building = 35,
    residential_building = 36,
    supply_commodity = 37
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

static vector<Construction> residential_constructions={
    {11,1000,residential,common,5,{534,T},1,{{wood_factory,5.0f}},"ľ��"},
    {12,1000,residential,common,5,{534,T},1,{{steel_plant,5.0f}},"�ֽṹ��"},
    {13,1000,residential,common,5,{587,T},15,{{residential_building,1.0f}},"ƽ��"},
    {14,1100,residential,common,5,{11.6,a},15,{{supply_commodity,70.0f}},"С�͹�Ԣ"},
    {15,1000,residential,common,5,{534,T},10,{{convenience_store,5.0f}},"����¥"},
    {16,1100,residential,rare,4,{2.76,a},15,{{industrial_building,0.6f},{online,0.8f}},"�˲Ź�Ԣ"},
    {17,1100,residential,rare,4,{2.01,a},10,{{trade_center,4.0f},{supply_commodity,40.0f}},"��԰��"},
    {18,1100,residential,rare,4,{2.76,a},15,{{online,0.8f},{residential_building,0.6f}},"��ʽС¥"},
    {19,1181,residential,epic,3,{8.43,a},1,{{online,0.6f},{folk_food,3.0f}},"���б���"},
    {20,1100,residential,epic,2,{274,T},10,{{offline,0.2f},{supply_commodity,20.0f}},"���˹���"},
};

static vector<Construction> commercial_constructions={
    {1,1000,commercial,common,5,{534,T},5,{{residential_buildings,5.0f}},"������"},
    {2,1000,commercial,common,5,{534,T},25,{{book_shop,5.0f}},"ѧУ"},
    {3,1000,commercial,common,5,{534,T},25,{{textile_mill,5.0f}},"��װ��"},
    {4,1000,commercial,common,5,{534,T},15,{{parts_factory,5.0f}},"����"},
    {5,1000,commercial,common,5,{534,T},5,{{food_manufacturer,5.0f}},"���г�"},
    {6,1000,commercial,rare,4,{106,T},15,{{paper_mill,4.0f},{school,4.0f}},"ͼ���"},
    {7,1000,commercial,rare,4,{109,T},5,{{garden_house,4.0f},{supply_commodity,40.0f}},"��ó����"},
    {8,1000,commercial,rare,4,{128,T},25,{{people_petroleum,2.0f},{offline,0.4f}},"����վ"},
    {9,1100,commercial,epic,3,{749,T},5,{{air_villa,3.0f},{online,0.6f}},"��ʳի"},
    {10,1101,commercial,epic,3,{823,T},15,{{offline,0.3f},{all,0.15f}},"ý��֮��"},
};

static vector<Construction> industrial_constructions={
    {21,1167,industrial,common,5,{86.3,a},35,{{online,1.4f}},"�糧"},
    {22,1000,industrial,common,5,{534,T},15,{{wooden_house,5.0f}},"ľ�ĳ�"},
    {23,1000,industrial,common,5,{534,T},35,{{book_shop,5.0f}},"��ֽ��"},
    {24,1150,industrial,common,5,{54.8,a},35,{{offline,0.3f}},"ˮ��"},
    {25,1000,industrial,common,5,{534,T},25,{{food_market,5.0f}},"ʳƷ��"},
    {26,1100,industrial,rare,4,{1.97,a},15,{{steel_house,4.0f},{industrial_building,0.6f}},"������"},
    {27,1000,industrial,epic,3,{26.7,T},15,{{petrol_station,3.0f},{offline,0.3f}},"����ʯ��"},
    {28,1000,industrial,rare,4,{106,T},35,{{clothing_store,4.0f},{commercial_building,0.6f}},"��֯��"},
    {29,1001,industrial,rare,4,{110,T},25,{{hardware_store,4.0f},{penguin_machinery,2.0f}},"�����"},
    {30,1000,industrial,epic,3,{35.5,T},25,{{parts_factory,3.0f},{all,0.3f}},"����е"}
};

static map<int,float>city_mission={{12,1.5f},{15,1.5f},{14,1.0f}};

static vector<pair<string,Attribute>> china_travelogues={
    {"�ĸ￪��",{all,0.2f}},{"һ��һ·",{commercial_building,0.6f}},{"�й�����",{industrial_building,0.6f}},
    {"ǿ���˾�",{offline,0.2f}},{"�����й�",{online,0.2f}},{"�������",{offline,0.2f}},
    {"��ƶ�漣",{residential_building,0.6f}},{"һ������",{all,0.2f}},{"�Ļ�����",{online,0.2f}},
    {"��øС��Ҹ��С���ȫ��",{all,0.2f}},

    {"�Ƹ�ʯ��",{all,0.1f}},{"ƽң�ų�",{supply_commodity,2.0f}},{"��ȸ¥",{offline,0.1f}},
    {"������",{supply_commodity,2.0f}},{"��̨ɽ",{online,0.1f}},{"�����ٲ�",{all,0.1f}},
    {"ú̿��ʡ",{industrial_building,0.3f}},{"�ϳ´�",{residential_building,0.3f}},{"�ھ�",{supply_commodity,2.0f}},
    {"�鶴����",{offline,0.1f}},

    {"����ɺ�����",{offline,0.1f}},{"Ԫ�϶���ַ",{offline,0.1f}},{"��ͷ�١��ɹų���",{residential_building,0.3f}},
    {"��ȫ��",{supply_commodity,2.0f}},{"�Ǵ�Ľ���",{online,0.1f}},{"��������",{commercial_building,0.3f}},
    {"��ú����",{industrial_building,0.3f}},{"����Ʒ",{supply_commodity,2.0f}},{"���ױ������ԭ",{residential_building,0.3f}},
    {"�͵�����ɳĮԽҰ��",{all,0.1f}},

    {"�й�һ���ַ",{offline,0.1f}},{"������ԥ԰",{offline,0.1f}},{"�������������",{all,0.1f}},
    {"�������й���",{online,0.1f}},{"��̲",{commercial_building,0.3f}},{"�ֶ���������ó��",{industrial_building,0.3f}},
    {"�й����ʽ��ڲ�����",{supply_commodity,2.0f}},{"�Ϻ�������Ӱ��Ƭ��",{commercial_building,0.3f}},{"ʯ����",{residential_building,0.3f}},
    {"�����",{residential_building,0.3f}},

    {"̫��",{online,0.1f}},{"����",{online,0.1f}},{"����԰��",{offline,0.1f}},
    {"��բз",{supply_commodity,2.0f}},{"�Ͼ���������",{all,0.1f}},{"����ɽ",{offline,0.1f}},
    {"������",{residential_building,0.3f}},{"�����",{residential_building,0.3f}},{"������ɰ��",{commercial_building,0.3f}},
    {"�껨̨",{offline,0.1f}},

    {"����",{all,0.1f}},{"Խ��",{online,0.1f}},{"���绥�������",{commercial_building,0.3f}},
    {"����С��Ʒ",{commercial_building,0.3f}},{"����ɽ",{offline,0.1f}},{"�����Ϻ��촬",{offline,0.1f}},
    {"������纣����",{supply_commodity,2.0f}},{"������ɽ��",{industrial_building,0.3f}},{"���",{residential_building,0.3f}},
    {"��ˮ��ɽ���ǽ�ɽ��ɽ����",{all,0.1f}},

    {"��������",{all,0.1f}},{"���������",{all,0.1f}},{"���Ͳ�",{supply_commodity,2.0f}},
    {"��ع�·�����ع�·",{industrial_building,0.3f}},{"������",{offline,0.1f}},{"������",{all,0.1f}},
    {"��ľ���",{online,0.1f}},{"��֥�һ�",{online,0.1f}},{"������",{online,0.1f}},
    {"�ƿ�",{residential_building,0.3f}},

    {"����ٸ",{all,0.1f}},{"����ʥ��",{all,0.1f}},{"����",{offline,0.1f}},
    {"������",{online,0.1f}},{"��������",{supply_commodity,2.0f}},{"��ǻ",{online,0.1f}},
    {"������ǽ",{industrial_building,0.3f}},{"��������",{residential_building,0.3f}},{"������",{residential_building,0.3f}},
    {"��ɽ",{offline,0.1f}},

    {"�ػ�Ī�߿�",{all,0.1f}},{"��Ȫ���Ƿ�������",{all,0.1f}},{"������",{offline,0.1f}},
    {"����Ͽˮ��",{industrial_building,0.3f}},{"��������",{supply_commodity,2.0f}},{"��̤����",{commercial_building,0.3f}},
    {"�߲ʵ�ϼ",{online,0.1f}},{"���ɽʯ��",{offline,0.1f}},{"��Ƥ����",{online,0.1f}},
    {"��������",{residential_building,0.3f}},

    {"��Դ�Ͳ˻�",{online,0.1f}},{"������",{offline,0.1f}},{"�����·",{industrial_building,0.3f}},
    {"�ຣ����",{residential_building,0.3f}},{"����Դ",{offline,0.1f}},{"���ͻ�",{online,0.1f}},
    {"�ɿ�����",{all,0.1f}},{"������",{supply_commodity,2.0f}},{"���ຣ�����г���",{commercial_building,0.3f}},
    {"���Ƽ�������",{industrial_building,0.3f}},

    {"���",{supply_commodity,2.0f}},{"��ͭϿˮ����Ŧ",{industrial_building,0.3f}},{"����ɽ",{offline,0.1f}},
    {"��������",{offline,0.1f}},{"����Ӱ��",{commercial_building,0.3f}},{"�γ�̲��",{supply_commodity,2.0f}},
    {"��ɳ�����ݷ���",{all,0.1f}},{"ɳ��ͷ",{online,0.1f}},{"�ƺӴ���",{industrial_building,0.3f}},
    {"����ɽ",{all,0.1f}},

    {"�����",{commercial_building,0.3f}},{"������",{offline,0.1f}},{"����˹��",{offline,0.1f}},
    {"������˹�ڰ�",{industrial_building,0.3f}},{"��ɽ���",{all,0.1f}},{"������",{supply_commodity,2.0f}},
    {"�½��Ϲ�",{supply_commodity,2.0f}},{"��ץ���������⴮",{supply_commodity,2.0f}},{"�������",{online,0.1f}},
    {"�½������������",{all,0.1f}},
};

static vector<pair<string,Attribute>> policy_center={
    {"һ��һ·����",{all,1.0f}},{"����ó��������",{commercial_building,3.0f}},{"����Э����չ",{residential_building,3.0f}},

    {"ȫ����ĸ�",{all,2.0f}},{"ȫ�������ι�",{online,2.0f}},{"�ƽ��˹�",{offline,2.0f}},{"��������",{industrial_building,6.0f}},

    {"����ǿ��",{industrial_building,12.0f}},{"�Ż�Ӫ�̻���",{supply_commodity,30.0f}},{"��˰����",{all,4.0f}},{"�ջݽ���",{commercial_building,12.0f}},

    {"���ͳ���",{residential_building,12.0f}},{"�������",{online,2.0f}},{"��׼��ƶ",{offline,6.0f}},{"��һ���˹�����",{all,2.0f}},
};

static float home_light=0.15f;
static Unit unit = b;
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

static float all_addition=2.5f;
static float online_addition=2.1f;
static float offline_addition=2.6f;
static float commercial_addition=3.6f;
static float industrial_addition=4.2f;
static float residential_addtion=4.5f;
static float supply_addition=34.0f;

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
            if(city_mission.find(35)!=city_mission.end())
            {
                city_mission_addition_online +=city_mission.find(35)->second;
                city_mission_addition_offline +=city_mission.find(35)->second;
            }

            if(current_addition.find(35)!=current_addition.end())
            {
                current_construction_addition_online +=current_addition.find(35)->second;
                current_construction_addition_offline +=current_addition.find(35)->second;
            }

            policy_center_addition_online += all_policy_addition+industrial_policy_addition+online_policy_addition+home_light;
            china_travelogues_addition_online += all_addition+industrial_addition+online_addition;

            policy_center_addition_offline += all_policy_addition+industrial_policy_addition+offline_policy_addition+home_light;
            china_travelogues_addition_offline += all_addition+industrial_addition+offline_addition;
            break;
        case commercial:
            if(city_mission.find(34)!=city_mission.end())
            {
                city_mission_addition_online +=city_mission.find(34)->second;
                city_mission_addition_offline +=city_mission.find(34)->second;
            }

            if(current_addition.find(34)!=current_addition.end())
            {
                current_construction_addition_online +=current_addition.find(34)->second;
                current_construction_addition_offline +=current_addition.find(34)->second;
            }

            policy_center_addition_online += all_policy_addition+commercial_policy_addition+online_policy_addition+home_light;
            china_travelogues_addition_online += all_addition+commercial_addition+online_addition;

            policy_center_addition_offline += all_policy_addition+commercial_policy_addition+offline_policy_addition+home_light;
            china_travelogues_addition_offline += all_addition+commercial_addition+offline_addition;
            break;
        case residential:
            if(city_mission.find(36)!=city_mission.end())
            {
                city_mission_addition_online +=city_mission.find(36)->second;
                city_mission_addition_offline +=city_mission.find(36)->second;
            }

            if(current_addition.find(36)!=current_addition.end())
            {
                current_construction_addition_online +=current_addition.find(36)->second;
                current_construction_addition_offline +=current_addition.find(36)->second;
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
        if(city_mission.find(32)!=city_mission.end())
        {
            city_mission_addition_online +=city_mission.find(32)->second;
        }
        if(city_mission.find(33)!=city_mission.end())
        {
            city_mission_addition_offline +=city_mission.find(33)->second;
        }
        if(city_mission.find(31)!=city_mission.end())
        {
            city_mission_addition_online +=city_mission.find(31)->second;
            city_mission_addition_offline +=city_mission.find(31)->second;
        }

        if(city_mission.find(37)!=city_mission.end())
        {
            supply +=city_mission.find(37)->second;
        }

        if(current_addition.find(id)!=current_addition.end())
        {
            current_construction_addition_online +=current_addition.find(id)->second;
            current_construction_addition_offline +=current_addition.find(id)->second;
        }
        if(current_addition.find(32)!=current_addition.end())
        {
            current_construction_addition_online +=current_addition.find(32)->second;
        }
        if(current_addition.find(33)!=current_addition.end())
        {
            current_construction_addition_offline +=current_addition.find(33)->second;
        }
        if(current_addition.find(31)!=current_addition.end())
        {
            current_construction_addition_online +=current_addition.find(31)->second;
            current_construction_addition_offline +=current_addition.find(31)->second;
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
        if(i==0)cout<<"��ҵ������"<<endl;
        if(i==3)cout<<"סլ������"<<endl;
        if(i==6)cout<<"��ҵ������"<<endl;
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

void ComputeAddition(float &all_addition,float &online_addition,float &offline_addition,
                    float &commercial_addition,float &industrial_addition,
                    float &residential_addtion,float &supply_addition)
{
    for(auto it : china_travelogues)
    {
        Attribute attribute = it.second;
        switch (attribute.first) {
        case 31:
            if(abs(attribute.second-0.1f)>0.01f && it.first != "�ĸ￪��" && it.first != "һ������" && it.first != "��øС��Ҹ��С���ȫ��")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            all_addition += (0.0f+attribute.second);
            break;
        case 32:
            if(abs(attribute.second-0.1f)>0.01f && it.first != "�����й�" && it.first != "�Ļ�����")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            online_addition += (0.0f+attribute.second);
            break;
        case 33:
            if(abs(attribute.second-0.1f)>0.01f && it.first != "ǿ���˾�" && it.first != "�������")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            offline_addition += (0.0f+attribute.second);
            break;
        case 34:
            if(abs(attribute.second-0.3f)>0.01f && it.first != "һ��һ·")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            commercial_addition += (0.0f+attribute.second);
            break;
        case 35:
            if(abs(attribute.second-0.3f)>0.01f && it.first != "�й�����")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            industrial_addition += (0.0f+attribute.second);
            break;
        case 36:
            if(abs(attribute.second-0.3f)>0.01f && it.first != "��ƶ�漣")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            residential_addtion += (0.0f+attribute.second);
            break;
        case 37:
            if(abs(attribute.second-2.0f)>0.01f )
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            supply_addition += attribute.second;
            break;
        default:
            cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            break;
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
        case 31:
            all_addition += (0.0f+attribute.second);
            break;
        case 32:
            online_addition += (0.0f+attribute.second);
            break;
        case 33:
            offline_addition += (0.0f+attribute.second);
            break;
        case 34:
            commercial_addition += (0.0f+attribute.second);
            break;
        case 35:
            industrial_addition += (0.0f+attribute.second);
            break;
        case 36:
            residential_addtion += (0.0f+attribute.second);
            break;
        case 37:
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
        cout<<"���������룺"<<get<0>(income)<<" M"<<endl;
        cout<<"���������룺"<<get<1>(income)<<" M"<<endl;
        break;
    case B:
        cout<<"���������룺"<<get<0>(income)<<" B"<<endl;
        cout<<"���������룺"<<get<1>(income)<<" B"<<endl;
        break;
    case T:
        cout<<"���������룺"<<get<0>(income)<<" T"<<endl;
        cout<<"���������룺"<<get<1>(income)<<" T"<<endl;
        break;
    case a:
        cout<<"���������룺"<<get<0>(income)<<" aa"<<endl;
        cout<<"���������룺"<<get<1>(income)<<" aa"<<endl;
        break;
    case b:
        cout<<"���������룺"<<get<0>(income)<<" bb"<<endl;
        cout<<"���������룺"<<get<1>(income)<<" bb"<<endl;
        break;
    case c:
        cout<<"���������룺"<<get<0>(income)<<" cc"<<endl;
        cout<<"���������룺"<<get<1>(income)<<" cc"<<endl;
        break;
    }
    cout<<"�����Ľ�������"<<" "<<get<2>(income)<<"%"<<endl;
}

int main()
{
    HashConstruction();
    //ComputeAddition(all_addition,online_addition,offline_addition,commercial_addition,industrial_addition,residential_addtion,supply_addition);
    cout<<"-------�ҹ�֮��ӳ�--------"<<endl;
    cout<<"���н�����"<<all_addition<<endl;
    cout<<"�������н�����"<<online_addition<<endl;
    cout<<"�������н�����"<<offline_addition<<endl;
    cout<<"��ҵ������"<<commercial_addition<<endl;
    cout<<"��ҵ������"<<industrial_addition<<endl;
    cout<<"סլ������"<<residential_addtion<<endl;
    cout<<"������"<<supply_addition<<endl;

    ComputePolicyAddition(all_policy_addition,online_policy_addition,offline_policy_addition,commercial_policy_addition,industrial_policy_addition,residential_policy_addtion,supply_policy_addition);
    cout<<"-------�������ļӳ�--------"<<endl;
    cout<<"���н�����"<<all_policy_addition<<endl;
    cout<<"�������н�����"<<online_policy_addition<<endl;
    cout<<"�������н�����"<<offline_policy_addition<<endl;
    cout<<"��ҵ������"<<commercial_policy_addition<<endl;
    cout<<"��ҵ������"<<industrial_policy_addition<<endl;
    cout<<"סլ������"<<residential_policy_addtion<<endl;
    cout<<"������"<<supply_policy_addition<<endl;

    vector<tuple<size_t,size_t,size_t>> commercial_set = SelectConstruction(commercial_constructions);
    vector<tuple<size_t,size_t,size_t>> industrial_set = SelectConstruction(industrial_constructions);
    vector<tuple<size_t,size_t,size_t>> residential_set = SelectConstruction(residential_constructions);

    map<int,pair<float,float>> all_current_construction;
    all_current_construction.insert({14,{0.0f,0.0f}});
    all_current_construction.insert({15,{0.0f,0.0f}});
    all_current_construction.insert({17,{0.0f,0.0f}});
    all_current_construction.insert({1,{0.0f,0.0f}});
    all_current_construction.insert({2,{0.0f,0.0f}});
    all_current_construction.insert({3,{0.0f,0.0f}});
    all_current_construction.insert({22,{0.0f,0.0f}});
    all_current_construction.insert({23,{0.0f,0.0f}});
    all_current_construction.insert({21,{0.0f,0.0f}});


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
    cout<<"-------�����������--------"<<endl;
    PrintResult(max_online_construction);
    PrintResult(onlineincome);


    tuple<float,float,float> offlineincome = ComputeIncome(max_offline_construction);
    cout<<endl;
    cout<<"-------�����������--------"<<endl;
    PrintResult(max_offline_construction);
    PrintResult(offlineincome);

    tuple<float,float,float> supplyincome = ComputeIncome(max_supply_construction);
    cout<<endl;
    cout<<"-------��󹩻�����--------"<<endl;
    PrintResult(max_supply_construction);
    PrintResult(supplyincome);
    return 0;
}
