#pragma once

#include <windows.h>
#include <GeneralDefinitions.h>
#include <Interfaces.h>

namespace WOLAPI {
	// Forward references and typedefs
	interface IRTPatcher;
	interface IRTPatcherEvent;
	interface IChat;
	interface IChatEvent;
	/*disp*/interface IDownload;
	interface IDownloadEvent;
	interface INetUtil;
	interface INetUtilEvent;
	interface IChat2;
	interface IChat2Event;

	enum ELocale {
		LOC_UNKNOWN = 0,
		LOC_OTHER = 1,
		LOC_USA = 2,
		LOC_CANADA = 3,
		LOC_UK = 4,
		LOC_GERMANY = 5,
		LOC_FRANCE = 6,
		LOC_SPAIN = 7,
		LOC_NETHERLANDS = 8,
		LOC_BELGIUM = 9,
		LOC_AUSTRIA = 10,
		LOC_SWITZERLAND = 11,
		LOC_ITALY = 12,
		LOC_DENMARK = 13,
		LOC_SWEDEN = 14,
		LOC_NORWAY = 15,
		LOC_FINLAND = 16,
		LOC_ISRAEL = 17,
		LOC_SOUTH_AFRICA = 18,
		LOC_JAPAN = 19,
		LOC_SOUTH_KOREA = 20,
		LOC_CHINA = 21,
		LOC_SINGAPORE = 22,
		LOC_TAIWAN = 23,
		LOC_MALAYSIA = 24,
		LOC_AUSTRALIA = 25,
		LOC_NEW_ZEALAND = 26,
		LOC_BRAZIL = 27,
		LOC_THAILAND = 28,
		LOC_ARGENTINA = 29,
		LOC_PHILIPPINES = 30,
		LOC_GREECE = 31,
		LOC_IRELAND = 32,
		LOC_POLAND = 33,
		LOC_PORTUGAL = 34,
		LOC_MEXICO = 35,
		LOC_RUSSIA = 36,
		LOC_TURKEY = 37
	};

	struct TServer {
		int gametype;
		int chattype;
		int timezone;
		float longitude;
		float lattitude;
		TServer* next;
		char name[71];
		char connlabel[5];
		char conndata[128];
		char login[10];
		char password[10];
	};

	struct TChannel {
		int type;
		unsigned int minUsers;
		unsigned int maxUsers;
		unsigned int currentUsers;
		unsigned int official;
		unsigned int tournament;
		unsigned int ingame;
		unsigned int flags;
		unsigned long reserved;
		unsigned long ipaddr;
		int latency;
		int hidden;
		TChannel* next;
		char name[17];
		char topic[81];
		char location[65];
		char key[9];
		char exInfo[41];
	};

	struct TUser {
		unsigned int flags;
		int group;
		unsigned long reserved;
		unsigned long reserved2;
		unsigned long reserved3;
		unsigned long squadID;
		unsigned long ipaddr;
		unsigned long squad_icon;
		TUser* next;
		char name[10];
		char squadname[41];
		char squadabbrev[10];
		ELocale Locale;
		int team;
	};

	struct TUpdate {
		unsigned long SKU;
		unsigned long version;
		int required;
		TUpdate* next;
		char Server[65];
		char patchpath[256];
		char patchfile[33];
		char login[33];
		char password[65];
		char localpath[256];
	};

	struct TSquad {
		unsigned long id;
		int SKU;
		int members;
		int color1;
		int color2;
		int color3;
		int icon1;
		int icon2;
		int icon3;
		TSquad* next;
		int rank;
		int team;
		int status;
		char email[81];
		char icq[17];
		char motto[81];
		char URL[129];
		char name[41];
		char abbreviation[41];
	};

	struct TLadder {
		unsigned int SKU;
		unsigned int team_no;
		unsigned int wins;
		unsigned int losses;
		unsigned int points;
		unsigned int kills;
		unsigned int rank;
		unsigned int rung;
		unsigned int disconnects;
		unsigned int team_rung;
		unsigned int provisional;
		unsigned int last_game_date;
		unsigned int win_streak;
		unsigned int reserved1;
		unsigned int reserved2;
		TLadder* next;
		char login_name[40];
		ELocale Locale;
	};

	struct THighscore {
		unsigned int SKU;
		unsigned int wins;
		unsigned int losses;
		unsigned int points;
		unsigned int rank;
		unsigned int accomplishments;
		THighscore* next;
		char login_name[40];
	};

	enum GTYPE_ {
		Server_ = 0,
		Channel_ = 1,
		CLIENT_ = 2
	};

	// {925CDEDE-71B9-11D1-B1C5-006097176556}
	interface IRTPatcher : IUnknown
	{
		virtual HRESULT _stdcall ApplyPatch( LPSTR destpath, LPSTR filename);
		virtual HRESULT _stdcall PumpMessages();
	};

	// {925CDEE3-71B9-11D1-B1C5-006097176556}
	interface IRTPatcherEvent : IUnknown
	{
		virtual HRESULT _stdcall OnProgress(LPSTR filename, int progress);
		virtual HRESULT _stdcall OnTermination(long success);
	};

	// {4DD3BAF4-7579-11D1-B1C6-006097176556}
	interface IChat : IUnknown
	{
		virtual HRESULT _stdcall PumpMessages();
		virtual HRESULT _stdcall RequestServerList(
				unsigned long SKU,
				unsigned long current_version,
				LPSTR loginname,
				LPSTR password,
				int timeout);
		virtual HRESULT _stdcall RequestConnection(TServer* Server, int timeout, int domangle);
		virtual HRESULT _stdcall RequestChannelList(int channelType, int autoping);
		virtual HRESULT _stdcall RequestChannelCreate(TChannel* Channel);
		virtual HRESULT _stdcall RequestChannelJoin(TChannel* Channel);
		virtual HRESULT _stdcall RequestChannelLeave();
		virtual HRESULT _stdcall RequestUserList();
		virtual HRESULT _stdcall RequestPublicMessage(LPSTR message);
		virtual HRESULT _stdcall RequestPrivateMessage(TUser* users, LPSTR message);
		virtual HRESULT _stdcall RequestLogout();
		virtual HRESULT _stdcall RequestPrivateGameOptions(TUser* users, LPSTR options);
		virtual HRESULT _stdcall RequestPublicGameOptions(LPSTR options);
		virtual HRESULT _stdcall RequestPublicAction(LPSTR action);
		virtual HRESULT _stdcall RequestPrivateAction(TUser* users, LPSTR action);
		virtual HRESULT _stdcall RequestGameStart(TUser* users);
		virtual HRESULT _stdcall RequestChannelTopic(LPSTR topic);
		virtual HRESULT _stdcall GetVersion(unsigned long* version);
		virtual HRESULT _stdcall RequestUserKick(TUser* User);
		virtual HRESULT _stdcall RequestUserIP(TUser* User);
		virtual HRESULT _stdcall GetGametypeInfo(
				unsigned int gtype,
				int icon_size,
				unsigned char** bitmap,
				int* bmp_bytes,
				LPSTR* name,
				LPSTR* URL);
		virtual HRESULT _stdcall RequestFind(TUser* User);
		virtual HRESULT _stdcall RequestPage(TUser* User, LPSTR message);
		virtual HRESULT _stdcall SetFindPage(int findOn, int pageOn);
		virtual HRESULT _stdcall SetSquelch(TUser* User, int squelch);
		virtual HRESULT _stdcall GetSquelch(TUser* User);
		virtual HRESULT _stdcall SetChannelFilter(int channelType);
		virtual HRESULT _stdcall RequestGameEnd();
		virtual HRESULT _stdcall SetLangFilter(int onoff);
		virtual HRESULT _stdcall RequestChannelBan(LPSTR name, int ban);
		virtual HRESULT _stdcall GetGametypeList(LPSTR* list);
		virtual HRESULT _stdcall GetHelpURL(LPSTR* URL);
		virtual HRESULT _stdcall SetProductSKU(unsigned long SKU);
		virtual HRESULT _stdcall GetNick(int num, LPSTR* nick, LPSTR* pass);
		virtual HRESULT _stdcall SetNick(int num, LPSTR nick, LPSTR pass, int domangle);
		virtual HRESULT _stdcall GetLobbyCount(int* count);
		virtual HRESULT _stdcall RequestRawMessage(LPSTR ircmsg);
		virtual HRESULT _stdcall GetAttributeValue(LPSTR attrib, LPSTR* value);
		virtual HRESULT _stdcall SetAttributeValue(LPSTR attrib, LPSTR value);
		virtual HRESULT _stdcall SetChannelExInfo(LPSTR info);
		virtual HRESULT _stdcall StopAutoping();
		virtual HRESULT _stdcall RequestSquadInfo(unsigned long id);
		virtual HRESULT _stdcall RequestSetTeam(int team);
		virtual HRESULT _stdcall RequestSetLocale(ELocale Locale);
		virtual HRESULT _stdcall RequestUserLocale(TUser* users);
		virtual HRESULT _stdcall RequestUserTeam(TUser* users);
		virtual HRESULT _stdcall GetNickLocale(int nicknum, ELocale* Locale);
		virtual HRESULT _stdcall SetNickLocale(int nicknum, ELocale Locale);
		virtual HRESULT _stdcall GetLocaleString(LPSTR* loc_string, ELocale Locale);
		virtual HRESULT _stdcall GetLocaleCount(int* num);
		virtual HRESULT _stdcall SetClientVersion(unsigned long version);
		virtual HRESULT _stdcall SetCodepageFilter(int filter);
		virtual HRESULT _stdcall RequestBuddyList();
		virtual HRESULT _stdcall RequestBuddyAdd(TUser* newbuddy);
		virtual HRESULT _stdcall RequestBuddyDelete(TUser* buddy);
		virtual HRESULT _stdcall RequestPublicUnicodeMessage(unsigned short* message);
		virtual HRESULT _stdcall RequestPrivateUnicodeMessage(TUser* users, unsigned short* message);
		virtual HRESULT _stdcall RequestPublicUnicodeAction(unsigned short* action);
		virtual HRESULT _stdcall RequestPrivateUnicodeAction(TUser* users, unsigned short* action);
		virtual HRESULT _stdcall RequestUnicodePage(TUser* User, unsigned short* message);
		virtual HRESULT _stdcall RequestSetPlayerCount(unsigned int currentPlayers, unsigned int maxPlayers);
		virtual HRESULT _stdcall RequestServerTime();
		virtual HRESULT _stdcall RequestInsiderStatus(TUser* users);
		virtual HRESULT _stdcall RequestSetLocalIP();
	};

	// {4DD3BAF6-7579-11D1-B1C6-006097176556}
	interface IChatEvent : IUnknown
	{
		virtual HRESULT _stdcall OnServerList(HRESULT res, TServer* servers);
		virtual HRESULT _stdcall OnUpdateList(HRESULT res, TUpdate* updates);
		virtual HRESULT _stdcall OnServerError(HRESULT res, LPSTR ircmsg);
		virtual HRESULT _stdcall OnConnection(HRESULT res, LPSTR motd);
		virtual HRESULT _stdcall OnMessageOfTheDay(HRESULT res, LPSTR motd);
		virtual HRESULT _stdcall OnChannelList(HRESULT res, TChannel* channels);
		virtual HRESULT _stdcall OnChannelCreate(HRESULT res, TChannel* Channel);
		virtual HRESULT _stdcall OnChannelJoin(HRESULT res, TChannel* Channel, TUser* User);
		virtual HRESULT _stdcall OnChannelLeave(HRESULT res, TChannel* Channel, TUser* User);
		virtual HRESULT _stdcall OnChannelTopic(HRESULT res, TChannel* Channel, LPSTR topic);
		virtual HRESULT _stdcall OnPrivateAction(HRESULT res, TUser* User, LPSTR action);
		virtual HRESULT _stdcall OnPublicAction(HRESULT res, TChannel* Channel, TUser* User, LPSTR action);
		virtual HRESULT _stdcall OnUserList(HRESULT res, TChannel* Channel, TUser* users);
		virtual HRESULT _stdcall OnPublicMessage(HRESULT res, TChannel* Channel, TUser* User, LPSTR message);
		virtual HRESULT _stdcall OnPrivateMessage(HRESULT res, TUser* User, LPSTR message);
		virtual HRESULT _stdcall OnSystemMessage(HRESULT res, LPSTR message);
		virtual HRESULT _stdcall OnNetStatus(HRESULT res);
		virtual HRESULT _stdcall OnLogout(HRESULT status, TUser* User);
		virtual HRESULT _stdcall OnPrivateGameOptions(HRESULT res, TUser* User, LPSTR options);
		virtual HRESULT _stdcall OnPublicGameOptions(HRESULT res, TChannel* Channel, TUser* User, LPSTR options);
		virtual HRESULT _stdcall OnGameStart(HRESULT res, TChannel* Channel, TUser* users, int gameid);
		virtual HRESULT _stdcall OnUserKick(HRESULT res, TChannel* Channel, TUser* kicked, TUser* kicker);
		virtual HRESULT _stdcall OnUserIP(HRESULT res, TUser* User);
		virtual HRESULT _stdcall OnFind(HRESULT res, TChannel* chan);
		virtual HRESULT _stdcall OnPageSend(HRESULT res);
		virtual HRESULT _stdcall OnPaged(HRESULT res, TUser* User, LPSTR message);
		virtual HRESULT _stdcall OnServerBannedYou(HRESULT res, long bannedTill);
		virtual HRESULT _stdcall OnUserFlags(HRESULT res, LPSTR name, unsigned int flags, unsigned int mask);
		virtual HRESULT _stdcall OnChannelBan(HRESULT res, LPSTR name, int banned);
		virtual HRESULT _stdcall OnSquadInfo(HRESULT res, unsigned long id, TSquad* Squad);
		virtual HRESULT _stdcall OnUserLocale(HRESULT res, TUser* users);
		virtual HRESULT _stdcall OnUserTeam(HRESULT res, TUser* users);
		virtual HRESULT _stdcall OnSetLocale(HRESULT res, ELocale newlocale);
		virtual HRESULT _stdcall OnSetTeam(HRESULT res, int newteam);
		virtual HRESULT _stdcall OnBuddyList(HRESULT res, TUser* buddy_list);
		virtual HRESULT _stdcall OnBuddyAdd(HRESULT res, TUser* buddy_added);
		virtual HRESULT _stdcall OnBuddyDelete(HRESULT res, TUser* buddy_deleted);
		virtual HRESULT _stdcall OnPublicUnicodeMessage(HRESULT res, TChannel* Channel, TUser* User, unsigned short* message);
		virtual HRESULT _stdcall OnPrivateUnicodeMessage(HRESULT res, TUser* User, unsigned short* message);
		virtual HRESULT _stdcall OnPrivateUnicodeAction(HRESULT res, TUser* User, unsigned short* action);
		virtual HRESULT _stdcall OnPublicUnicodeAction(HRESULT res, TChannel* Channel, TUser* User, unsigned short* action);
		virtual HRESULT _stdcall OnPagedUnicode(HRESULT res, TUser* User, unsigned short* message);
		virtual HRESULT _stdcall OnServerTime(HRESULT res, long stime);
		virtual HRESULT _stdcall OnInsiderStatus(HRESULT res, TUser* users);
		virtual HRESULT _stdcall OnSetLocalIP(HRESULT res, LPSTR message);
	};

	// {4DD3BAF5-7579-11D1-B1C6-006097176556}
	class Chat : public IChat, IChatEvent {
	};

	// {0BF5FCEB-9F03-11D1-9DC7-006097C54321}
	/**disp*/interface IDownload
	{
		void QueryInterface(
				GUID* riid,
				__out void** ppvObj);
		unsigned long AddRef();
		unsigned long Release();
		void DownloadFile(
				LPSTR Server,
				LPSTR login,
				LPSTR password,
				LPSTR file,
				LPSTR localfile,
				LPSTR regkey);
		void Abort();
		void PumpMessages();
	};

	// {6869E99D-9FB4-11D1-9DC8-006097C54321}
	interface IDownloadEvent : IUnknown
	{
		virtual HRESULT _stdcall OnEnd();
		virtual HRESULT _stdcall OnError(int error);
		virtual HRESULT _stdcall OnProgressUpdate(
				int bytesread,
				int totalsize,
				int timetaken,
				int timeleft);
		virtual HRESULT _stdcall OnQueryResume();
		virtual HRESULT _stdcall OnStatusUpdate(int status);
	};

	class Download : public IDownload, IDownloadEvent {
	};

	// {B832B0AA-A7D3-11D1-97C3-00609706FA0C}
	interface INetUtil : IUnknown
	{
		virtual HRESULT _stdcall RequestGameresSend(
				LPSTR host,
				int port,
				unsigned char* data,
				int length);
		virtual HRESULT _stdcall RequestLadderSearch(
				LPSTR host,
				int port,
				LPSTR key,
				unsigned long SKU,
				int team,
				int cond,
				int sort,
				int number,
				int leading);
		virtual HRESULT _stdcall RequestLadderList(
				LPSTR host,
				int port,
				LPSTR keys,
				unsigned long SKU,
				int team,
				int cond,
				int sort);
		virtual HRESULT _stdcall RequestPing(
				LPSTR host,
				int timeout,
				int* handle);
		virtual HRESULT _stdcall PumpMessages();
		virtual HRESULT _stdcall GetAvgPing(
				unsigned long ip,
				int* avg);
		virtual HRESULT _stdcall RequestNewNick(
				LPSTR nick,
				LPSTR pass,
				LPSTR email,
				LPSTR parentEmail,
				int newsletter,
				int shareinfo);
		virtual HRESULT _stdcall RequestAgeCheck(
				int month,
				int day,
				int year,
				LPSTR email);
		virtual HRESULT _stdcall RequestWDTState(
				LPSTR host,
				int port,
				unsigned char request);
		virtual HRESULT _stdcall RequestLocaleLadderList(
				LPSTR host,
				int port,
				LPSTR keys,
				unsigned long SKU,
				int team,
				int cond,
				int sort,
				ELocale Locale);
		virtual HRESULT _stdcall RequestLocaleLadderSearch(
				LPSTR host,
				int port,
				LPSTR key,
				unsigned long SKU,
				int team,
				int cond,
				int sort,
				int number,
				int leading,
				ELocale Locale);
		virtual HRESULT _stdcall RequestHighscore(
				LPSTR host,
				int port,
				LPSTR keys,
				unsigned long SKU);
	};

	// {B832B0AC-A7D3-11D1-97C3-00609706FA0C}
	interface INetUtilEvent : IUnknown
	{
		virtual HRESULT _stdcall OnPing(
				HRESULT res,
				int time,
				unsigned long ip,
				int handle);
		virtual HRESULT _stdcall OnLadderList(
				HRESULT res,
				TLadder* list,
				int totalCount,
				long timeStamp,
				int keyRung);
		virtual HRESULT _stdcall OnGameresSent(HRESULT res);
		virtual HRESULT _stdcall OnNewNick(
				HRESULT res,
				LPSTR message,
				LPSTR nick,
				LPSTR pass);
		virtual HRESULT _stdcall OnAgeCheck(
				HRESULT res,
				int years,
				int consent);
		virtual HRESULT _stdcall OnWDTState(
				HRESULT res,
				unsigned char* state,
				int length);
		virtual HRESULT _stdcall OnHighscore(
				HRESULT res,
				THighscore* list,
				int totalCount,
				long timeStamp,
				int keyRung);
	};

	// {B832B0AB-A7D3-11D1-97C3-00609706FA0C}
	class NetUtil : public INetUtil, INetUtilEvent {
	};

	// {8B938190-EF3F-11D1-9808-00609706FA0C}
	interface IChat2 : IUnknown
	{
		virtual HRESULT _stdcall PumpMessages();
		virtual HRESULT _stdcall RequestConnection(
				TServer* Server,
				int timeout);
		virtual HRESULT _stdcall RequestMessage(
				unsigned long who,
				LPSTR message);
		virtual HRESULT _stdcall GetTypeFromGID(
				unsigned long id,
				GTYPE_* type);
		virtual HRESULT _stdcall RequestChannelList();
		virtual HRESULT _stdcall RequestChannelJoin(LPSTR name);
		virtual HRESULT _stdcall RequestChannelLeave(TChannel* chan);
		virtual HRESULT _stdcall RequestUserList(TChannel* chan);
		virtual HRESULT _stdcall RequestLogout();
		virtual HRESULT _stdcall RequestChannelCreate(TChannel* chan);
		virtual HRESULT _stdcall RequestRawCmd(LPSTR cmd);
	};

	// {8B938192-EF3F-11D1-9808-00609706FA0C}
	interface IChat2Event : IUnknown
	{
		virtual HRESULT _stdcall OnNetStatus(HRESULT res);
		virtual HRESULT _stdcall OnMessage(
				HRESULT res,
				TUser* User,
				LPSTR message);
		virtual HRESULT _stdcall OnChannelList(
				HRESULT res,
				TChannel* list);
		virtual HRESULT _stdcall OnChannelJoin(
				HRESULT res,
				TChannel* chan,
				TUser* User);
		virtual HRESULT _stdcall OnLogin(HRESULT res);
		virtual HRESULT _stdcall OnUserList(
				HRESULT res,
				TChannel* chan,
				TUser* users);
		virtual HRESULT _stdcall OnChannelLeave(
				HRESULT res,
				TChannel* chan,
				TUser* User);
		virtual HRESULT _stdcall OnChannelCreate(
				HRESULT res,
				TChannel* chan);
		virtual HRESULT _stdcall OnUnknownLine(
				HRESULT res,
				LPSTR line);
	};

	// {8B938191-EF3F-11D1-9808-00609706FA0C}
	class Chat2 : public IChat2, IChat2Event {
	};

}
