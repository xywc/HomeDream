#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <map>
using namespace std;

enum ConstrcutionType {industrial,commercial,residential}; //声明枚举类型
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
    {11,1000,residential,common,5,{534,'T'},1,{{wood_factory,5.0f}},"木屋"},
    {12,1000,residential,common,5,{534,'T'},1,{{steel_plant,5.0f}},"钢结构房"},
    {13,1000,residential,common,5,{587,'T'},15,{{residential_building,1.0f}},"平房"},
    {14,1000,residential,common,5,{630,'T'},15,{{supply_commodity,70.0f}},"小型公寓"},
    {15,1000,residential,common,5,{534,'T'},10,{{convenience_store,5.0f}},"居民楼"},
    {16,600,residential,rare,4,{2.74,'B'},15,{{industrial_building,0.6f},{online,0.8f}},"人才公寓"},
    {17,1001,residential,rare,3,{28.2,'T'},10,{{trade_center,3.0f},{supply_commodity,30.0f}},"花园洋房"},
    {18,500,residential,rare,3,{54.3,'M'},15,{{online,0.6f},{residential_building,0.45f}},"中式小楼"},
    {19,600,residential,epic,3,{744,'M'},1,{{online,0.4f},{folk_food,2.0f}},"空中别墅"},
    {20,600,residential,epic,1,{136,'M'},10,{{offline,0.1f},{supply_commodity,10.0f}},"复兴公馆"},
};

static vector<Construction> commercial_constructions={
    {1,1000,commercial,common,5,{534,'T'},5,{{residential_buildings,5.0f}},"便利店"},
    {2,1000,commercial,common,5,{534,'T'},25,{{book_shop,5.0f}},"学校"},
    {3,1000,commercial,common,5,{534,'T'},25,{{textile_mill,5.0f}},"服装店"},
    {4,1000,commercial,common,5,{534,'T'},15,{{parts_factory,5.0f}},"五金店"},
    {5,1000,commercial,common,5,{534,'T'},5,{{food_manufacturer,5.0f}},"菜市场"},
    {6,1000,commercial,rare,4,{106,'T'},15,{{paper_mill,4.0f},{school,4.0f}},"图书城"},
    {7,1000,commercial,rare,3,{27.2,'T'},5,{{garden_house,3.0f},{supply_commodity,30.0f}},"商贸中心"},
    {8,805,commercial,rare,3,{136,'B'},25,{{people_petroleum,1.5f},{offline,0.3f}},"加油站"},
    {9,800,commercial,epic,3,{149,'B'},5,{{air_villa,3.0f},{online,0.6f}},"民食斋"},
    {10,800,commercial,epic,3,{158,'B'},15,{{offline,0.3f},{all,0.15f}},"媒体之声"},
};

static vector<Construction> industrial_constructions={
    {21,1049,industrial,common,5,{2.61,'a'},35,{{online,1.4f}},"电厂"},
    {22,1000,industrial,common,5,{534,'T'},15,{{wooden_house,5.0f}},"木材厂"},
    {23,1000,industrial,common,5,{534,'T'},35,{{book_shop,5.0f}},"造纸厂"},
    {24,1000,industrial,common,5,{673,'T'},35,{{offline,0.3f}},"水厂"},
    {25,1000,industrial,common,5,{534,'T'},25,{{food_market,5.0f}},"食品厂"},
    {26,800,industrial,rare,4,{392,'B'},15,{{steel_house,4.0f},{industrial_building,0.6f}},"钢铁厂"},
    {27,801,industrial,epic,3,{101,'B'},15,{{petrol_station,3.0f},{offline,0.3f}},"人民石油"},
    {28,800,industrial,rare,3,{98.2,'B'},35,{{clothing_store,3.0f},{commercial_building,0.45f}},"纺织厂"},
    {29,700,industrial,rare,3,{6.67,'B'},25,{{hardware_store,3.0f},{penguin_machinery,1.5f}},"零件厂"},
    {30,900,industrial,epic,2,{691,'B'},25,{{parts_factory,2.0f},{all,0.2f}},"企鹅机械"}
};

static vector<pair<string,float>>city_mission={{"water_plant",1.0f},{"power_plant",2.0f}};

static vector<Attribute>policy_center={{industrial_building,12.0f},{all,4.0f},{commercial_building,12.0f},{supply_commodity,25.0f}};

static vector<pair<string,Attribute>> china_travelogues={
    {"改革开发",{all,0.2f}},{"一带一路",{commercial_building,0.6f}},{"中国制造",{industrial_building,0.6f}},
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
        if(i==0)cout<<"商业建筑："<<endl;
        if(i==3)cout<<"住宅建筑："<<endl;
        if(i==6)cout<<"工业建筑："<<endl;
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
    cout<<"所有建筑："<<all_addition<<endl;
    cout<<"在线所有建筑："<<online_addition<<endl;
    cout<<"离线所有建筑："<<offline_addition<<endl;
    cout<<"商业建筑："<<commercial_addition<<endl;
    cout<<"工业建筑："<<industrial_addition<<endl;
    cout<<"住宅建筑："<<residential_addtion<<endl;
    cout<<"供货："<<supply_addition<<endl;
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
//    cout<<"供货的奖励增加"<<" "<<supply<<"%"<<endl;

    set<int> max_online_construction;
    set<int> max_offline_construction;
    set<int> max_supply_construction;
    float supply=0.0f;
    OptimizeConstruction(commercial_set,industrial_set,residential_set,max_online_construction,
                         max_offline_construction,max_supply_construction,supply);
    supply += supply_addition + 45;

    cout<<endl;
    cout<<"-------最大供货奖励--------"<<endl;
    PrintResult(max_supply_construction);
    cout<<"供货的奖励增加"<<" "<<supply<<"%"<<endl;
    return 0;
}
