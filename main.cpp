#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <map>
using namespace std;

enum ConstrcutionType {industrial,commercial,residential}; //����ö������
enum Quality {common,rare,epic};

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
    pair<float,char> income;
    int income_interval;
    vector<Attribute> attribute;
    string name;
};

static vector<Construction> residential_constructions={
    {11,1000,residential,common,5,{534,'T'},1,{{wood_factory,5.0f}},"ľ��"},
    {12,1000,residential,common,5,{534,'T'},1,{{steel_plant,5.0f}},"�ֽṹ��"},
    {13,1000,residential,common,5,{587,'T'},15,{{residential_building,1.0f}},"ƽ��"},
    {14,1000,residential,common,5,{630,'T'},15,{{supply_commodity,70.0f}},"С�͹�Ԣ"},
    {15,1000,residential,common,5,{534,'T'},10,{{convenience_store,5.0f}},"����¥"},
    {16,600,residential,rare,4,{2.74,'B'},15,{{industrial_building,0.6f},{online,0.8f}},"�˲Ź�Ԣ"},
    {17,1001,residential,rare,3,{28.2,'T'},10,{{trade_center,3.0f},{supply_commodity,30.0f}},"��԰��"},
    {18,500,residential,rare,3,{54.3,'M'},15,{{online,0.6f},{residential_building,0.45f}},"��ʽС¥"},
    {19,600,residential,epic,3,{744,'M'},1,{{online,0.4f},{folk_food,2.0f}},"���б���"},
    {20,600,residential,epic,1,{136,'M'},10,{{offline,0.1f},{supply_commodity,10.0f}},"���˹���"},
};

static vector<Construction> commercial_constructions={
    {1,1000,commercial,common,5,{534,'T'},5,{{residential_buildings,5.0f}},"������"},
    {2,1000,commercial,common,5,{534,'T'},25,{{book_shop,5.0f}},"ѧУ"},
    {3,1000,commercial,common,5,{534,'T'},25,{{textile_mill,5.0f}},"��װ��"},
    {4,1000,commercial,common,5,{534,'T'},15,{{parts_factory,5.0f}},"����"},
    {5,1000,commercial,common,5,{534,'T'},5,{{food_manufacturer,5.0f}},"���г�"},
    {6,1000,commercial,rare,4,{106,'T'},15,{{paper_mill,4.0f},{school,4.0f}},"ͼ���"},
    {7,1000,commercial,rare,3,{27.2,'T'},5,{{garden_house,3.0f},{supply_commodity,30.0f}},"��ó����"},
    {8,805,commercial,rare,3,{136,'B'},25,{{people_petroleum,1.5f},{offline,0.3f}},"����վ"},
    {9,800,commercial,epic,3,{149,'B'},5,{{air_villa,3.0f},{online,0.6f}},"��ʳի"},
    {10,800,commercial,epic,3,{158,'B'},15,{{offline,0.3f},{all,0.15f}},"ý��֮��"},
};

static vector<Construction> industrial_constructions={
    {21,1049,industrial,common,5,{2.61,'a'},35,{{online,1.4f}},"�糧"},
    {22,1000,industrial,common,5,{534,'T'},15,{{wooden_house,5.0f}},"ľ�ĳ�"},
    {23,1000,industrial,common,5,{534,'T'},35,{{book_shop,5.0f}},"��ֽ��"},
    {24,1000,industrial,common,5,{673,'T'},35,{{offline,0.3f}},"ˮ��"},
    {25,1000,industrial,common,5,{534,'T'},25,{{food_market,5.0f}},"ʳƷ��"},
    {26,800,industrial,rare,4,{392,'B'},15,{{steel_house,4.0f},{industrial_building,0.6f}},"������"},
    {27,801,industrial,epic,3,{101,'B'},15,{{petrol_station,3.0f},{offline,0.3f}},"����ʯ��"},
    {28,800,industrial,rare,3,{98.2,'B'},35,{{clothing_store,3.0f},{commercial_building,0.45f}},"��֯��"},
    {29,700,industrial,rare,3,{6.67,'B'},25,{{hardware_store,3.0f},{penguin_machinery,1.5f}},"�����"},
    {30,900,industrial,epic,2,{691,'B'},25,{{parts_factory,2.0f},{all,0.2f}},"����е"}
};

static vector<pair<string,float>>city_mission={{"water_plant",1.0f},{"power_plant",2.0f}};

static vector<Attribute>policy_center={{industrial_building,12.0f},{all,4.0f},{commercial_building,12.0f},{supply_commodity,25.0f}};

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

static float home_light=0.95f;

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

float ComputeSupplyIncome(set<int> &all_current_construction)
{
//    float commercial_income= 0.0f;
//    float residential = 0.0f;
//    float industrial_income= 0.0f;
//    float total_income = 0.0f;
//    float online_income= 0.0f;
//    float offline_income = 0.0f;
    float supply = 0.0f;

    for(auto id : all_current_construction)
    {
        vector<Attribute> attribute = allconstructions[id].attribute;
        for(auto attr : attribute)
        {
            if(attr.first == supply_commodity)
            {
                supply += attr.second;
            }
        }
    }
    return supply;
}

void OptimizeConstruction(vector<tuple<size_t,size_t,size_t>> commercial_set,
                            vector<tuple<size_t,size_t,size_t>> industrial_set,
                            vector<tuple<size_t,size_t,size_t>> residential_set,
                            set<int> &max_online_construction,set<int> &max_offline_construction,
                            set<int> &max_supply_construction,float &supply)
{
    set<int> current_commercial;
    set<int> current_industrial;
    set<int> current_residential;
    set<int> all_current_construction;
    for(size_t i=0;i<commercial_set.size();++i)
    {
        for(size_t j=0;j<industrial_set.size();++j)
        {
            for(size_t k=0;k<industrial_set.size();++k)
            {
                current_commercial.clear();
                current_industrial.clear();
                current_residential.clear();
                all_current_construction.clear();

                current_commercial.insert(commercial_constructions[get<0>(commercial_set[i])].id);
                current_commercial.insert(commercial_constructions[get<1>(commercial_set[i])].id);
                current_commercial.insert(commercial_constructions[get<2>(commercial_set[i])].id);

                current_industrial.insert(industrial_constructions[get<0>(industrial_set[j])].id);
                current_industrial.insert(industrial_constructions[get<1>(industrial_set[j])].id);
                current_industrial.insert(industrial_constructions[get<2>(industrial_set[j])].id);

                current_residential.insert(residential_constructions[get<0>(residential_set[k])].id);
                current_residential.insert(residential_constructions[get<1>(residential_set[k])].id);
                current_residential.insert(residential_constructions[get<2>(residential_set[k])].id);

                all_current_construction.insert(current_commercial.begin(),current_commercial.end());
                all_current_construction.insert(current_industrial.begin(),current_industrial.end());
                all_current_construction.insert(current_residential.begin(),current_residential.end());

                float current_supply =  ComputeSupplyIncome(all_current_construction);
                if(current_supply > supply)
                {
                    supply = current_supply;
                    max_supply_construction = all_current_construction;
                }
            }
        }
    }
}

void ComputePercent(float &all_addition,float &online_addition,float &offline_addition,
                    float &commercial_addition,float &industrial_addition,
                    float &residential_addtion,float &supply_addition)
{
    for(auto it : china_travelogues)
    {
        Attribute attribute = it.second;
        switch (attribute.first) {
        case 31:
            if(abs(attribute.second-0.1f)>0.01f )
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            all_addition *= (1.0f+attribute.second);
            break;
        case 32:
            if(abs(attribute.second-0.1f)>0.01f )
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            online_addition *= (1.0f+attribute.second);
            break;
        case 33:
            if(abs(attribute.second-0.1f)>0.01f )
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            offline_addition *= (1.0f+attribute.second);
            break;
        case 34:
            if(abs(attribute.second-0.3f)>0.01f )
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            commercial_addition *= (1.0f+attribute.second);
            break;
        case 35:
            if(abs(attribute.second-0.3f)>0.01f )
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            industrial_addition *= (1.0f+attribute.second);
            break;
        case 36:
            if(abs(attribute.second-0.3f)>0.01f )
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            residential_addtion *= (1.0f+attribute.second);
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

void PrintResult(set<int> all_current_construction)
{
    int i=0;
    for(int id : all_current_construction)
    {
        if(i==0)cout<<"��ҵ������"<<endl;
        if(i==3)cout<<"סլ������"<<endl;
        if(i==6)cout<<"��ҵ������"<<endl;
        cout<<"   "<<allconstructions[id].name<<" "<<endl;
        i++;
    }
}
int main()
{
    float all_addition=1.0f;
    float online_addition=1.0f;
    float offline_addition=1.0f;
    float commercial_addition=1.0f;
    float industrial_addition=1.0f;
    float residential_addtion=1.0f;
    float supply_addition=0.0f;
    HashConstruction();

    ComputePercent(all_addition,online_addition,offline_addition,commercial_addition,
                   industrial_addition,residential_addtion,supply_addition);
    cout<<"���н�����"<<all_addition<<endl;
    cout<<"�������н�����"<<online_addition<<endl;
    cout<<"�������н�����"<<offline_addition<<endl;
    cout<<"��ҵ������"<<commercial_addition<<endl;
    cout<<"��ҵ������"<<industrial_addition<<endl;
    cout<<"סլ������"<<residential_addtion<<endl;
    cout<<"������"<<supply_addition<<endl;
    vector<tuple<size_t,size_t,size_t>> commercial_set = SelectConstruction(commercial_constructions);
    vector<tuple<size_t,size_t,size_t>> industrial_set = SelectConstruction(industrial_constructions);
    vector<tuple<size_t,size_t,size_t>> residential_set = SelectConstruction(residential_constructions);

    set<int> current_commercial;
    set<int> current_industrial;
    set<int> current_residential;
    set<int> all_current_construction;

    current_industrial.insert(29);
    current_industrial.insert(30);
    current_industrial.insert(25);

    current_commercial.insert(7);
    current_commercial.insert(6);
    current_commercial.insert(2);

    current_residential.insert(13);
    current_residential.insert(16);
    current_residential.insert(14);

    all_current_construction.insert(current_commercial.begin(),current_commercial.end());
    all_current_construction.insert(current_industrial.begin(),current_industrial.end());
    all_current_construction.insert(current_residential.begin(),current_residential.end());

//    float supply = ComputeSupplyIncome(all_current_construction);
//    supply += supply_addition + 45;
//    cout<<"�����Ľ�������"<<" "<<supply<<"%"<<endl;

    set<int> max_online_construction;
    set<int> max_offline_construction;
    set<int> max_supply_construction;
    float supply=0.0f;
    OptimizeConstruction(commercial_set,industrial_set,residential_set,max_online_construction,
                         max_offline_construction,max_supply_construction,supply);
    supply += supply_addition + 45;

    cout<<endl;
    cout<<"-------��󹩻�����--------"<<endl;
    PrintResult(max_supply_construction);
    cout<<"�����Ľ�������"<<" "<<supply<<"%"<<endl;
    return 0;
}
