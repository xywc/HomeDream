#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <map>
#include <math.h>
using namespace std;

enum ConstrcutionType {industrial,commercial,residential}; //声明枚举类型
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
    {11,1000,residential,common,5,{534,T},1,{{wood_factory,5.0f}},"木屋"},
    {12,1000,residential,common,5,{534,T},1,{{steel_plant,5.0f}},"钢结构房"},
    {13,1000,residential,common,5,{587,T},15,{{residential_building,1.0f}},"平房"},
    {14,1100,residential,common,5,{11.6,a},15,{{supply_commodity,70.0f}},"小型公寓"},
    {15,1000,residential,common,5,{534,T},10,{{convenience_store,5.0f}},"居民楼"},
    {16,1100,residential,rare,4,{2.76,a},15,{{industrial_building,0.6f},{online,0.8f}},"人才公寓"},
    {17,1100,residential,rare,4,{2.01,a},10,{{trade_center,4.0f},{supply_commodity,40.0f}},"花园洋房"},
    {18,1100,residential,rare,4,{2.76,a},15,{{online,0.8f},{residential_building,0.6f}},"中式小楼"},
    {19,1181,residential,epic,3,{8.43,a},1,{{online,0.6f},{folk_food,3.0f}},"空中别墅"},
    {20,1100,residential,epic,2,{274,T},10,{{offline,0.2f},{supply_commodity,20.0f}},"复兴公馆"},
};

static vector<Construction> commercial_constructions={
    {1,1000,commercial,common,5,{534,T},5,{{residential_buildings,5.0f}},"便利店"},
    {2,1000,commercial,common,5,{534,T},25,{{book_shop,5.0f}},"学校"},
    {3,1000,commercial,common,5,{534,T},25,{{textile_mill,5.0f}},"服装店"},
    {4,1000,commercial,common,5,{534,T},15,{{parts_factory,5.0f}},"五金店"},
    {5,1000,commercial,common,5,{534,T},5,{{food_manufacturer,5.0f}},"菜市场"},
    {6,1000,commercial,rare,4,{106,T},15,{{paper_mill,4.0f},{school,4.0f}},"图书城"},
    {7,1000,commercial,rare,4,{109,T},5,{{garden_house,4.0f},{supply_commodity,40.0f}},"商贸中心"},
    {8,1000,commercial,rare,4,{128,T},25,{{people_petroleum,2.0f},{offline,0.4f}},"加油站"},
    {9,1100,commercial,epic,3,{749,T},5,{{air_villa,3.0f},{online,0.6f}},"民食斋"},
    {10,1101,commercial,epic,3,{823,T},15,{{offline,0.3f},{all,0.15f}},"媒体之声"},
};

static vector<Construction> industrial_constructions={
    {21,1167,industrial,common,5,{86.3,a},35,{{online,1.4f}},"电厂"},
    {22,1000,industrial,common,5,{534,T},15,{{wooden_house,5.0f}},"木材厂"},
    {23,1000,industrial,common,5,{534,T},35,{{book_shop,5.0f}},"造纸厂"},
    {24,1150,industrial,common,5,{54.8,a},35,{{offline,0.3f}},"水厂"},
    {25,1000,industrial,common,5,{534,T},25,{{food_market,5.0f}},"食品厂"},
    {26,1100,industrial,rare,4,{1.97,a},15,{{steel_house,4.0f},{industrial_building,0.6f}},"钢铁厂"},
    {27,1000,industrial,epic,3,{26.7,T},15,{{petrol_station,3.0f},{offline,0.3f}},"人民石油"},
    {28,1000,industrial,rare,4,{106,T},35,{{clothing_store,4.0f},{commercial_building,0.6f}},"纺织厂"},
    {29,1001,industrial,rare,4,{110,T},25,{{hardware_store,4.0f},{penguin_machinery,2.0f}},"零件厂"},
    {30,1000,industrial,epic,3,{35.5,T},25,{{parts_factory,3.0f},{all,0.3f}},"企鹅机械"}
};

static map<int,float>city_mission={{12,1.5f},{15,1.5f},{14,1.0f}};

static vector<pair<string,Attribute>> china_travelogues={
    {"改革开放",{all,0.2f}},{"一带一路",{commercial_building,0.6f}},{"中国制造",{industrial_building,0.6f}},
    {"强国兴军",{offline,0.2f}},{"美丽中国",{online,0.2f}},{"体育大国",{offline,0.2f}},
    {"减贫奇迹",{residential_building,0.6f}},{"一国两制",{all,0.2f}},{"文化自信",{online,0.2f}},
    {"获得感、幸福感、安全感",{all,0.2f}},

    {"云冈石窟",{all,0.1f}},{"平遥古城",{supply_commodity,2.0f}},{"鹳雀楼",{offline,0.1f}},
    {"刀削面",{supply_commodity,2.0f}},{"五台山",{online,0.1f}},{"壶口瀑布",{all,0.1f}},
    {"煤炭大省",{industrial_building,0.3f}},{"老陈醋",{residential_building,0.3f}},{"汾酒",{supply_commodity,2.0f}},
    {"洪洞大槐树",{offline,0.1f}},

    {"额济纳胡杨林",{offline,0.1f}},{"元上都遗址",{offline,0.1f}},{"马头琴、蒙古长调",{residential_building,0.3f}},
    {"烤全羊",{supply_commodity,2.0f}},{"那达慕大会",{online,0.1f}},{"乌兰牧骑",{commercial_building,0.3f}},
    {"羊煤土气",{industrial_building,0.3f}},{"奶制品",{supply_commodity,2.0f}},{"呼伦贝尔大草原",{residential_building,0.3f}},
    {"巴丹吉林沙漠越野赛",{all,0.1f}},

    {"中共一大会址",{offline,0.1f}},{"城隍庙豫园",{offline,0.1f}},{"东方明珠电视塔",{all,0.1f}},
    {"世博会中国馆",{online,0.1f}},{"外滩",{commercial_building,0.3f}},{"浦东新区、自贸区",{industrial_building,0.3f}},
    {"中国国际进口博览会",{supply_commodity,2.0f}},{"上海美术电影制片厂",{commercial_building,0.3f}},{"石库门",{residential_building,0.3f}},
    {"本帮菜",{residential_building,0.3f}},

    {"太湖",{online,0.1f}},{"昆曲",{online,0.1f}},{"江南园林",{offline,0.1f}},
    {"大闸蟹",{supply_commodity,2.0f}},{"南京长江大桥",{all,0.1f}},{"花果山",{offline,0.1f}},
    {"华西村",{residential_building,0.3f}},{"淮扬菜",{residential_building,0.3f}},{"宜兴紫砂壶",{commercial_building,0.3f}},
    {"雨花台",{offline,0.1f}},

    {"西湖",{all,0.1f}},{"越剧",{online,0.1f}},{"世界互联网大会",{commercial_building,0.3f}},
    {"义乌小商品",{commercial_building,0.3f}},{"普陀山",{offline,0.1f}},{"嘉兴南湖红船",{offline,0.1f}},
    {"杭州湾跨海大桥",{supply_commodity,2.0f}},{"宁波舟山港",{industrial_building,0.3f}},{"浙菜",{residential_building,0.3f}},
    {"绿水青山就是金山银山理念",{all,0.1f}},

    {"布达拉宫",{all,0.1f}},{"珠穆朗玛峰",{all,0.1f}},{"酥油茶",{supply_commodity,2.0f}},
    {"青藏公路、川藏公路",{industrial_building,0.3f}},{"大昭寺",{offline,0.1f}},{"藏羚羊",{all,0.1f}},
    {"纳木错湖",{online,0.1f}},{"林芝桃花",{online,0.1f}},{"格萨尔",{online,0.1f}},
    {"唐卡",{residential_building,0.3f}},

    {"兵马俑",{all,0.1f}},{"革命圣地",{all,0.1f}},{"秦岭",{offline,0.1f}},
    {"大雁塔",{online,0.1f}},{"羊肉泡馍",{supply_commodity,2.0f}},{"秦腔",{online,0.1f}},
    {"西安城墙",{industrial_building,0.3f}},{"安塞腰鼓",{residential_building,0.3f}},{"法门寺",{residential_building,0.3f}},
    {"华山",{offline,0.1f}},

    {"敦煌莫高窟",{all,0.1f}},{"酒泉卫星发射中心",{all,0.1f}},{"嘉峪关",{offline,0.1f}},
    {"刘家峡水库",{industrial_building,0.3f}},{"兰州拉面",{supply_commodity,2.0f}},{"马踏飞燕",{commercial_building,0.3f}},
    {"七彩丹霞",{online,0.1f}},{"麦积山石窟",{offline,0.1f}},{"羊皮筏子",{online,0.1f}},
    {"拉卜楞寺",{residential_building,0.3f}},

    {"门源油菜花",{online,0.1f}},{"塔尔寺",{offline,0.1f}},{"青藏铁路",{industrial_building,0.3f}},
    {"青海花儿",{residential_building,0.3f}},{"三江源",{offline,0.1f}},{"酥油花",{online,0.1f}},
    {"可可西里",{all,0.1f}},{"青稞酒",{supply_commodity,2.0f}},{"环青海湖自行车赛",{commercial_building,0.3f}},
    {"引黄济宁工程",{industrial_building,0.3f}},

    {"枸杞",{supply_commodity,2.0f}},{"青铜峡水利枢纽",{industrial_building,0.3f}},{"贺兰山",{offline,0.1f}},
    {"西夏王陵",{offline,0.1f}},{"西部影城",{commercial_building,0.3f}},{"盐池滩羊",{supply_commodity,2.0f}},
    {"治沙神器草方格",{all,0.1f}},{"沙坡头",{online,0.1f}},{"黄河大桥",{industrial_building,0.3f}},
    {"六盘山",{all,0.1f}},

    {"大巴扎",{commercial_building,0.3f}},{"坎儿井",{offline,0.1f}},{"喀纳斯湖",{offline,0.1f}},
    {"霍尔果斯口岸",{industrial_building,0.3f}},{"天山天池",{all,0.1f}},{"和田玉",{supply_commodity,2.0f}},
    {"新疆瓜果",{supply_commodity,2.0f}},{"手抓饭、烤羊肉串",{supply_commodity,2.0f}},{"民族歌舞",{online,0.1f}},
    {"新疆生产建设兵团",{all,0.1f}},
};

static vector<pair<string,Attribute>> policy_center={
    {"一带一路建设",{all,1.0f}},{"自由贸易区建设",{commercial_building,3.0f}},{"区域协调发展",{residential_building,3.0f}},

    {"全面深化改革",{all,2.0f}},{"全面依法治国",{online,2.0f}},{"科教兴国",{offline,2.0f}},{"创新驱动",{industrial_building,6.0f}},

    {"制造强国",{industrial_building,12.0f}},{"优化营商环境",{supply_commodity,30.0f}},{"减税降费",{all,4.0f}},{"普惠金融",{commercial_building,12.0f}},

    {"新型城镇化",{residential_building,12.0f}},{"乡村振兴",{online,2.0f}},{"精准扶贫",{offline,6.0f}},{"新一代人工智能",{all,2.0f}},
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

void ComputeAddition(float &all_addition,float &online_addition,float &offline_addition,
                    float &commercial_addition,float &industrial_addition,
                    float &residential_addtion,float &supply_addition)
{
    for(auto it : china_travelogues)
    {
        Attribute attribute = it.second;
        switch (attribute.first) {
        case 31:
            if(abs(attribute.second-0.1f)>0.01f && it.first != "改革开放" && it.first != "一国两制" && it.first != "获得感、幸福感、安全感")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            all_addition += (0.0f+attribute.second);
            break;
        case 32:
            if(abs(attribute.second-0.1f)>0.01f && it.first != "美丽中国" && it.first != "文化自信")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            online_addition += (0.0f+attribute.second);
            break;
        case 33:
            if(abs(attribute.second-0.1f)>0.01f && it.first != "强国兴军" && it.first != "体育大国")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            offline_addition += (0.0f+attribute.second);
            break;
        case 34:
            if(abs(attribute.second-0.3f)>0.01f && it.first != "一带一路")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            commercial_addition += (0.0f+attribute.second);
            break;
        case 35:
            if(abs(attribute.second-0.3f)>0.01f && it.first != "中国制造")
            {
                cout<<it.first<<" "<<attribute.first<<" "<<attribute.second<<endl;
            }
            industrial_addition += (0.0f+attribute.second);
            break;
        case 36:
            if(abs(attribute.second-0.3f)>0.01f && it.first != "减贫奇迹")
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
    //ComputeAddition(all_addition,online_addition,offline_addition,commercial_addition,industrial_addition,residential_addtion,supply_addition);
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
