#include <iostream>
#include "Qint.h"
#include "Qfloat.h"
#include "Utils.h"
#include "Convert.h"
#include "BitProcess.h"
#include "Utils.h"
#include <time.h>
#include <bitset>

#include <stdint.h>
#include <cstdint>

void testTask1_2()
{
	Qint aBig("0");
	Qint bBig("0");
	long long int a = 0;
	long long int b = 0;

	std::cout << "input int a = "; std::cin >> a;
	aBig = Qint(std::to_string(a));
	//std::cin >> aBig;

	std::cout << "input int b = "; std::cin >> b;
	bBig = Qint(std::to_string(b));
	//std::cin >> bBig;

	std::cout << std::endl;

	std::cout << "a \t\t= " << a << std::endl;
	std::cout << "aBig \t\t= " << aBig << std::endl;

	std::cout << "b \t\t= " << b << std::endl;
	std::cout << "bBig \t\t= " << bBig << std::endl;

	std::cout << "a + b \t\t= " << (a + b) << std::endl;
	std::cout << "aBig + bBig \t= " << (aBig + bBig) << std::endl;

	std::cout << "a - b \t\t= " << (a - b) << std::endl;
	std::cout << "aBig - bBig \t= " << (aBig - bBig) << std::endl;

	std::cout << "a * b \t\t= " << (a * b) << std::endl;
	std::cout << "aBig * bBig \t= " << (aBig * bBig) << std::endl;

	std::cout << "a / b \t\t= " << (a / b) << std::endl;
	std::cout << "aBig / bBig \t= " << (aBig / bBig) << std::endl;

	std::cout << "a & b \t\t= " << (a & b) << std::endl;
	std::cout << "aBig & bBig \t= " << (aBig & bBig) << std::endl;

	std::cout << "a | b \t\t= " << (a | b) << std::endl;
	std::cout << "aBig | bBig \t= " << (aBig | bBig) << std::endl;

	std::cout << "a ^ b \t\t= " << (a ^ b) << std::endl;
	std::cout << "aBig ^ bBig \t= " << (aBig ^ bBig) << std::endl;

	std::cout << "~a \t\t= " << (~a) << std::endl;
	std::cout << "~aBig \t\t= " << (~aBig) << std::endl;

	std::cout << "a << 5 \t\t= " << (a << 5) << std::endl;
	std::cout << "aBig << 5 \t= " << (aBig << 5) << std::endl;

	std::cout << "a >> 2 \t\t= " << (a >> 2) << std::endl;
	std::cout << "aBig >> 2 \t= " << (aBig >> 2) << std::endl;

	std::cout << std::endl;

	std::cout << "aBig > bBig: \t" << ((aBig > bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig < bBig: \t" << ((aBig < bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig == bBig: \t" << ((aBig == bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig != bBig: \t" << ((aBig != bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig >= bBig: \t" << ((aBig >= bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig <= bBig: \t" << ((aBig <= bBig) ? "true" : "false") << std::endl;

	std::cout << std::endl;

	/*std::cout << "input a Big num: ";
	Qint cBig;
	cBig.ScanQInt();
	bool* bits = cBig.DecToBin();*/
}

void showRawBitFloat(std::string str)
{
	for (unsigned int i = 0; i < NUM_OF_EXPONENT_BITS + NUM_OF_SIGNIFICANT_BITS + 1; i++)
	{
		if (i == 1 || i == 1 + NUM_OF_EXPONENT_BITS)
		{
			std::cout << std::endl;
		}
		std::cout << str[i];
	}
}

int main()
{
	//testTask1_2();
	//std::cout << Utils::NegativePowTwo(149) << std::endl;
	//std::string num1 = "0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001036028019110084017747910233316423448399931094085548961550381502271526326419859099362827438604263990440940502636295699148253955181821206727469617611515618877286846833720213589506677540102155478438311764240888638462632889000347383690891331525550121117196203652606256484537174009815684969981850334822372196318705265258826121930513793853290345151370929333255237512491161684238311625754332690200224544421088696006391819212040903794138890578860704504922674128554789589929985505869634422017173302307655013608267037370746751488422872376560652754295536617686045262992034483386986833766872097603501042180477828713872069334272309663599812029493661682382855094388936474854151789140080368658259544487351434474093562257627916597927093649982345837382273688630945836247165801823660010270632196282818340142846459193826411137116801132880446183827196146688300515520360381075687556955500251359268611395085055447621283766205301949383423512453044888170989347135477659853879406484138879394704851738451181627617593092420081765813196536516631621100808109529464097331037843446421769803803438942466045561048336623602964442265404601493420914381164741331812223569980065108326311444049031654162299440584798056827569009213464873572273135345538840404288064212318532595461396283270546470254828465063487771763871858663722273107272185621381611417883809939474644508503718515325316277847939797781643998449462102909319739513580156608804400148591009291733912920441454150858496012031982239731820902967947208880867417989617371637133971677124350043593476996638315579672298291375881900604973492840478133427418079834128595588969558715002152385112613602419285403741646384753734980544432043952459275851812039812622397599085537216775553887075393716786105572642274746880713767925226031446866109380505151929862711987829860699038857059421293527252421915562486776854679976906083200781970693634585082755688607969770761426209355199077217257416723850309143324147543125712197835037712834076327276718322510401502227780092909726193216940375017227067343145087587738958452705160185662936967811297133614251044066173483170678359553798322168066301298801412282102962057921039529286583247375662866879989692328517480431790709406835960589149526029253690052790180800774141498231078902019658386921195881004820366578714408096028499276435325558749472860191356133068435482358407125859943322315421051432381092820063802424333325997297644703151656946514237110395309535871935178081156899852285782338808741032117599230413109150018690277541238204515909321034198135429643984913748092976969803814556094869081802687882494042475031482293933630779097330607753192001409508573907440758996939823313675938316800596343385975977333326642648346007259249952062534654129516955723941063403775582439916439465141102591437183787219007665615827023950317151513065702116117113710966842234288369439950873134569808029383732765629246928225162752007421286880837881596382016225243057661327316786984723350045693822501305123255621249937396582174370125211124732283098747731962253645712849330072793184249319546998389031451107650995757195375579897936844684569371319404506933055504607924473440267976984890339171425127167955203299302757319369255717836167606522055966132069700894787231118470966308638543918184942429421886184082975286748841270272086343206689342041638110329988536283941190499618889106101999971203507957307786885889037717350970726338218565948184952840612407755737670482727907631372080189326811690120098083386800617369773158139910270946117035617291662197332242056526049083742251727887579641639103576926640320744713298996486001652645459302884829175474561915999475135829484421647642073413959582298705562138798989167908858027039391029664836195388844874030616625965192912281569605938630395021382335377428226164";
	//std::string num2 = "612192080401848171465846571398702771051330079083122893821647358780964153147678783889942626273637687633121368894407921487047732988521421703240687318053588414453243696935012287641046406369647203471846046116512811543478095091241916931720335496460107294618591129055287915257934450757335860505676100206919446148806276234220360562856810077102409393986538652596431098060448812575058550247987631554510262246861516132767712223875494934374903093492760156202408700143781934019105084217257974655926333723547738011188755714770216994977718252785871028543291736657231233267902310887637757775529138736441863583773399472650595550798340558652678697841956553270836428424994730889648650149097511199854859695287489285743051391019628307873262975208213450859338716573638570127743911808266396720572201396936502042025074549227933580545402411895794456129313785678086010779213191935506247100581021496251922331905162602976242946899382502242843672120870371576342816874502361012949949669570044229992827208432680779790324158311304445049515943076406029594291460151392103575636176075020071327614766590778195942576096411475833616702356409838018594223020825391881850456617663082946003116520120941139440376136924407837976793150017818343095645353699826971166457233932593284811476777943552659049920503325289225274293699278509864764444137243586756904640907100821963550184016720457530125205702837525348890765971119728724626540262139247457153544756359489619319863521852775361229900299575836602817631522906791056245225040111933825227904692039900829930712996620419393004980822565654388681583213954689596216966288668211938408195818182741277999038285135381123795140588028745566895910579877469016733293221808978468853639721061855286840490172471388383887093810953537880772990345130412748789588500658127230305865719888996279529880530681676846521735427415609208577149640714002398661566266114494808730446180003428650335074791045509615141678368207141767074742703060577369632134070864176642354205286247453956613422085233522197232016266720453421601622785219237350097097773929928945099979662958581388557481555331341823635910230391092231990802671460589361604868197961242468203125215239709326337856379832368811812324708134156961190937836987525386271982978389219768700496210136628111866042813089511067993166965222565457978746230475599432772263279457322958629756052920766723595746120742661649461018457602226385523194117767512463534295522581878237461301406539856182906990563542707034847660396232016093610775802589315998530280577722174875957085482213256588007254919445320794581009845025770956593668765886689824745388928894096922962926735700681466264184500258454639740691896632552115819854784184322526020620702496605609203580014131644698241122949373206987694558533336367408366462426453863576838778557264587303770196358285367558592324643504318958952517025207030805339888500616887155016748981410992594769538559930178724171097633305022914387893416966036283401577269007758065441085277951348293745685964674173264906781589719339437420915993549660365512872212001502297458457014697559607728332114498310380273968658239308680145192781423248383461181064516885125231277080197110410056963913065020995314146149012071117401205481991894348023554278892663135785409312407828209939295471658137048755575698271195105467851592859555416772190381123827603980168789744948712681428080862063686324532652270328177429174856998991679942070116490986495255336956514467243929369978974437834833901563282026612529081005849495771941803666626293175998756044380651512335237510886691208776795251829024652417651796958226382270136980405426251976977133836773053558360899537093595419039573479429162242041161860632674180188447540366370937209428254705788060181528757978827670595906714655863123310085285182159114335597056109477308795150194140344635057122371293840030062404547161594660660143504617555917122968250778953494309965124395706194180888699223442924970887952295932014358949175889415885032989239204321895304580206524918127869008923597120200158681767606935166472740150904973607145776572242003738585816175942520181661623728946238062241391681477499350702615375729030070025796347581841116901904598966605637696924826754561427332577734730643535454320067350497024910826257584810117578578732402609391068113459715116205316846433199608825514743996695523233547760079464163768716000808638607259908916563963393989617181226291014832511649904172004325872486627090436665002124753418410240715742784273730805286433624441274670626635493817839767399868938567846358127082538218388064981720388565945580821129766852494523637296569829923371350213683277598010365584377252263200989661575567953842086809426098648108774877085718034196126407220495105868202377371712244651788491743422003082939807773207722218974739146575580990280839550502616351270893029271357104195794679314006999175543440481993613634583733729219139924543371041659339517062834040949275117520184829517992735655420125215809553295502983270377036581521303497450556508696161212919188635858324766114436237536291995862417176441404220639008001356714182473563806096966275463604466499142140143564744631498729178614053555402480012965711259673309932378821415748216215353526023061000863021911972486554578042882199307436259555515707567843411635812909495208770905197520281618197487945967718726313551117451947489420820201914239888224133372058653955238268871021751781585829227592785532556733916170335700261308453601891969926470414484757906469850292850845494921750627071841279130489013791304799162842942662694906766598814061184014593299895787199414891209764277208733988604796230321961465877925813735629175476566327964558942219284496475171667836232643596371532032784867260451808140246515929725158806406937359088921383742411422168982872798630543204165494767640739901995637231587721633762357076671382267602248632414628519661981318935160862256719366076057708355962494593915261153956150847614720843628925981798288631470307726993463834559904127344811801071524154810303465764398337014059544456664302011904156664139247356490683689586096502614095072982471384575325545551378719912202500327866039245038853095365418513265328791196117211941934416340920457638639385583635290643793836427825678780201159203145163477512226810549125575414571214882922044401246404179568444108828644115789636941353587941034016348085756480293803717718586285285545899398165965733114737192828028056573425131827428555740111232828652456948027341107561996870014155822281667817910574757998425710995403718499261882293631188974135836287801498789253725164530424046834932807400510119765955456065682808326080176279596608462497001591859270860179805374541689705000393629817264801462521906303869757868390299676095448151953142432010589594157801547688758321982190012522183062114330610006967257556332229405285988394406712587081093871158803638058705481409718998332720858988737717803984264000385126781965631436465385312722661544991545957433070042755622701060733969518658347572018258302567447875303552539427940777855726141335438026330771094197989160580837875313101216963179546734141927787703337845809442101592820978627565922741886785210201469450811977284080994224361488983881868958840416732693851573864095869601297281217253524032062666880427577650827764991698412153518535587542450838928312472295797026482688425267033213229914000313289396366095031218055134303538739734661630718211195303425892171203175475462635134574746243904223254958263674411293409856176907877864864680005981326327859493193653356578465605649941017557523147897253799441350265470251478134840367487235201878639997731313832822269993461692563353577867297635988072918593129455140038950579184983896198575749540755827809914867491470870902141586962447404228055685380750504798878562372152561082034443187369544581730183818834603355365968522326502376921672822994571267320141863711435348358287271635974578426353802284026678421312689805189835460889879862519179589720741407887771856621839106082916259765625";
	//showRawBitFloat(Convert::ConvertFloatToBin(num1+num2));
	//std::string floatNum;
	//std::string bits;
	
	Qfloat a;

	while (true)
	{
		std::cout << "input a Qfloat: ";
		std::cin >> a;
		//std::cout << "bin: \n";
		//bits = Convert::ConvertFloatToBin(floatNum);
		//showRawBitFloat(bits);
		std::cout << std::endl;
		std::cout << "dec:\t\t" << a;//Convert::ConvertBinToFloat(bits);
		std::cout << std::endl;
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}
