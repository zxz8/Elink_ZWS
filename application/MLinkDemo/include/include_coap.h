
#ifndef DEMOS_APPLICATION_MLINKDEMO_INCLUDE_INCLUDE_COAP_H_
#define DEMOS_APPLICATION_MLINKDEMO_INCLUDE_INCLUDE_COAP_H_


#ifdef __cplusplus
extern "C"{
#endif


typedef enum
{
    // system server
    COAP_SYS_NOTI_CMD_RESET			= 0x0001,		//ϵͳ��λ
    COAP_SYS_NOTI_CMD_FACTORY		= 0x0002,		//
    COAP_SYS_NOTI_CMD_SYNCTIME		= 0x0003,
    COAP_SYS_NOTI_CMD_SETMESH		= 0x0004,		//�����豸������������״̬
    COAP_SYS_NOTI_CMD_SETNET		= 0x0005,
    COAP_SYS_NOTI_CMD_REGDEV		= 0x0006,
    COAP_SYS_NOTI_CMD_SETCLOUD		= 0x0007,
    COAP_SYS_NOTI_CMD_GETDEVINFO	= 0x0008,
    COAP_SYS_NOTI_CMD_SETADDR       = 0x0009,
    COAP_SYS_NOTI_CMD_KEEPALIVE     = 0x000a,
    COAP_SYS_NOTI_CMD_UPGRADE       = 0x000b,
    COAP_SYS_NOTI_CMD_RESETMESH     = 0x000c,
    COAP_SYS_NOTI_CMD_MQTT_INIT     = 0x000d,
    COAP_SYS_NOTI_CMD_SENDADDR      = 0x000e,
    COAP_SYS_NOTI_CMD_CLEARDATA     = 0x000f,
    COAP_SYS_NOTI_CMD_ERR           = 0x00ff,

    // discover server
    COAP_DISCOVER_NOTI_CMD_WHOIS	= 0x0111,
    COAP_DISCOVER_NOTI_CMD_IAM		= 0x0112,
    COAP_DISCOVER_NOTI_CMD_IHAV		= 0x0113,
    COAP_DISCOVER_NOTI_CMD_WHO_HAV  = 0x0114,
    COAP_DISCOVER_NOTI_CMD_ERR      = 0x011f,
    // manage server
    COAP_MANAGER_NOTI_CMD_GET		= 0x0221,
    COAP_MANAGER_NOTI_CMD_ADD		= 0x0222,
    COAP_MANAGER_NOTI_CMD_DEL		= 0x0223,
    COAP_MANAGER_NOTI_CMD_CLEAR		= 0x0224,
    COAP_MANAGER_NOTI_CMD_UPDATE	= 0x0225,
    COAP_MANAGER_NOTI_CMD_ERR       = 0x022f,
    // ctrl server
    COAP_CTRL_NOTI_CMD_READ			= 0x0331,
    COAP_CTRL_NOTI_CMD_WRITE		= 0x0332,
    COAP_CTRL_NOTI_CMD_READMULT		= 0x0333,
    COAP_CTRL_NOTI_CMD_WRITEMULT	= 0x0334,
    COAP_CTRL_NOTI_CMD_WRITEGROUP	= 0x0335,
    COAP_CTRL_NOTI_CMD_DEVSET		= 0x0336,
    COAP_CTRL_NOTI_CMD_SYNCSTATUS   = 0x0337,
    COAP_CTRL_NOTI_CMD_ERR          = 0x033f,
    //msg server
    COAP_MSG_NOTI_CMD_EVENT         = 0x0441,
    COAP_MSG_NOTI_CMD_LINKTASK      = 0x0442,
    COAP_MSG_NOTI_CMD_STATECHANGE   = 0x0443,
    COAP_MSG_NOTI_CMD_CHANGENOTIFY  = 0x0444,

    COAP_MSG_NOTI_CMD_ALLOW_NOTIFY  = 0x0445,
    //
    COAP_EVENT_NOTI_CMD_OBSERVER    = 0x04f0,
    COAP_SERVER_NOTI_CMD_ERR        = 0xffff
}COAP_NOTI_CMD_ID_E;

#define MLINK_ERR_MSG_FAIL                      "Message fail"
#define MLINK_ERR_GENERAL_ERROR                 "General error !!!"
#define MLINK_ERR_PUBLIC_PARAM_ERROR            "Public param error !!!"
#define MLINK_ERR_DATA_ILLEGAL                  "Data is illegal!!!"
#define MLINK_ERR_LACK_PARAM                    "Lack param!!!"
#define MLINK_ERR_DATA_VALIDATION_FAILURE       "Data validation failure!!!"
#define MLINK_ERR_OBJECT_EXISTED                "Object is existed!!!"
#define MLINK_ERR_NO_FINDING_OBJECT             "Found nothing!!!"

typedef enum
{
    MLINK_RESP_OK               = 0x00,     //ϵͳ��λ
    MLINK_RESP_ERROR            = 0x01,
    MLINK_RESP_ERR_PUBLIC       = 1000,
    MLINK_RESP_ILLEGAL          = 1001,
    MLINK_RESP_LACK_PARAM       = 1002,
    MLINK_RESP_CHECK_FAIL       = 1003,
    MLINK_RESP_OBJECT_EXISTED     = 2000,
    MLINK_RESP_FIND_NOTHING     = 2001
}MLINK_RESPONSE_STATUS_E;

typedef enum
{
    MLINK_EVENTLEVEL_ALARM,         //报警或告警事件
    MLINK_EVENTLEVEL_NOTI_EVENT,        //通知事件
    MLINK_EVENTLEVEL_NORMAL_EVENT,  //正常事件
}MLINK_EVENTLEVEL;

typedef enum
{
    MLINK_EVENTTYPE_UNKNOWN,                //未知
    MLINK_EVENTTYPE_DEV_CLOSE,              //设备关闭
    MLINK_EVENTTYPE_POWERFAIL_OFF_LINE,     //断电/离线
    MLINK_EVENTTYPE_ALARM_INFO,             //报警信息
    MLINK_EVENTTYPE_FAULT_INFO,             //故障信息
    MLINK_EVENTTYPE_STATE_CHANGE    = 10,   //状态变更
    MLINK_EVENTTYPE_VALUE_CHANGE,           //值改变
    MLINK_EVENTTYPE_COMMAND_FAIL,           //命令失败
    MLINK_EVENTTYPE_OFFEST_THRESHOLD,       //偏移阈值
    MLINK_EVENTTYPE_OFFEST_RANGE,           //偏离范围
    MLINK_EVENTTYPE_UNDER_BATTERY,          //电池欠压

    MLINK_EVENTTYPE_UNLOCK_RECORD   = 20,   //开锁记录
    MLINK_EVENTTYPE_OPERATION_RECORD,       //操作记录

}MLINK_EVENTTYPE;

typedef enum
{
    MLINK_NOTITYPE_ALARM,               //报警事件通知
    MLINK_NOTITYPE_STATE_CHANGE,        //状态变更通知
    MLINK_NOTITYPE_EVENT                //作为事件类型上报
}MLINK_NOTITYPE;
#ifdef __cplusplus
}
#endif

#endif /* DEMOS_APPLICATION_MLINKDEMO_INCLUDE_INCLUDE_COAP_H_ */
