/* mctrl.h - Motor Control Header File */

/* -------------------------------------------------------------------------- */
/*  MCTRL General ----------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

#define ON 1 // On state integer value;
#define OFF 0 // Off state integer value;

#define MAX_NAME 32 // Maximum length of mctrl.h parameter names;
#define MAX_USER 32 // Maximum length of Username string;
#define MAX_PATH 91 // Chosen based on AF_UNIX connectionless requirements;
#define MAX_DESC 255 // Maximum length of description string;

#define MAX_NETWORKS 16 // Maximum # of networks a device can be attached to.

/* -------------------------------------------------------------------------- */
/*  Connection and Nodes (MCU, MCTRL) --------------------------------------- */
/* -------------------------------------------------------------------------- */

#define UDP 0;
#define TCP 1;

typedef struct mcu
{
  unsigned int id; // Unique [integer] Mcu identifier > 0;
  char name[MAX_NAME]; // MCU name;
  char desc[MAX_DESC]; // MCU description;
  unsigned int ip; // MCU IP address;
  char path[MAX_PATH]; // MCU profile path;
} Mcu;

typedef struct mctrl
{
  unsigned int id; // Unique [integer] Mcu identifier > 0;
  char name[MAX_NAME]; // MCTRL name;
  char desc[MAX_DESC]; // MCTRL description;
  unsigned int ip; // MCTRL IP address;
  char path[MAX_PATH]; // MCTRL profile path;
} Mctrl;

typedef struct cxn
{
  unsigned int id; // Unique [integer] connection identifier > 0;
  char name[MAX_NAME]; // Connection name;
  int state; // Connection state (ON/OFF);
  Mcu *m_mcu; // Connection MCU identifier;
  Mctrl *m_mctrl; // Connection MCTRL identifier;
  int protocol; // {UDP, TCP};
  char path[MAX_PATH]; // CXN profile path;
} Cxn;

/* mctrl_newmcu()
   Create a new mcu. 
   Return positive ID integer on Success. Return -1 on failure. */

int mctrl_newmcu (Mcu *m_mcu);

/* mctrl_delmcu()
   Remove the specified mcu.
   Return 1 on Success. Return -1 on failure. */

int mctrl_delmcu (Mcu *m_mcu);

/* mctrl_print_mcu_info()
   Print info for the specified MCU to STDOUT. */

void mctrl_print_mcu_info (Mcu *m_mcu);

/* mctrl_newmctrl()
   Create a new MCTRL node.
   Return positive ID integer on Success. Return -1 on failure. */

int mctrl_newmctrl (Mctrl *m_mctrl);

/* mctrl_delmctrl()
   Remove the specified mctrl noe.
   Return 1 on success. Return -1 on failure. */

int mctrl_delmctrl (Mctrl *m_mctrl);

/* mctrl_print_mctrl_info()
   Print info for the specified MCTRL to STDOUT. */

void mctrl_print_mctrl_info (Mctrl *m_mctrl);

/* mctrl_connect()
   Connect the movement control node (MCTRL) to the 
   master control unit (MCU). 
   Return 1 on Success.  Return -1 on failure */

int mctrl_connect (Cxn *m_cxn, Mcu *m_mcu, Mctrl *m_mctrl, int protocol);

/* mctrl_connection_status()
   Return the connection status of the MCTRL node. {ON/OFF} */

int mctrl_connection_status (Cxn *m_cxn);

/* mctrl_print_connection_info()
   Print connection info for the specified cxn */

void mctrl_print_connection_info (Cxn *m_cxn);

/* -------------------------------------------------------------------------- */
/*  MCTRL Interface and Users ----------------------------------------------- */
/* -------------------------------------------------------------------------- */

typedef struct user
{
  unsigned int id; // Unique [integer] identifer;
  char name[MAX_USER]; // User name;
  char path[MAX_PATH]; // User profile path;
} User;

typedef struct iface
{
  int version; // Interface version number;
  char name[MAX_NAME]; // Interface name;
  char desc[MAX_DESC]; // Interface description;
  char user[MAX_USER]; // Current interface user;
  char path[MAX_PATH]; // Interface profile path;
  int state;
} Iface;

/* mctrl_newuser()
   Create a new user. 
   Return unique [integer] id > 0 on success. Return -1 on failure.*/

int mctrl_newuser (User *m_user);

/* mctrl_deluser() 
   Remove the specified user.
   Return 1 on success. Return -1 on failure. */

int mctrl_deluser (User *m_user);

/* mctrl_print_user_info()
   Print user information to STDOUT */

void mctrl_print_user_info (User *m_user);

/* mctrl_interface_en()
   Enable/Disable the MCTRL interface.
   Return the new interface state. {ON, OFF} */

int mctrl_interface_en (Iface *m_iface);

/* mctrl_interface_status()
   Return the status of the MCTRL interface. {ON, OFF} */

int mctrl_interface_statue (Iface *m_iface);

/* mctrl_print_interface_info()
   Print interface information to STDOUT */

void mctrl_print_interface_info (Iface *m_iface);

/* -------------------------------------------------------------------------- */
/*  MCTRL Device Network ---------------------------------------------------- */
/* -------------------------------------------------------------------------- */

typedef struct device
{
  unsigned int id; // Unique [integer] identifier > 0;
  char name[MAX_NAME]; // Device name;
  char desc[MAX_DESC]; // Device description;
  unsigned int net[MAX_NETWORKS]; // Identifiers of attached device networks;
  unsigned int type; // Device type flag byte (see defines in General section);
} Device;

/* mctrl_devnet_new()
   Create a new control network for movement system */

/* mctrl_devnet_link()
   Link the specified control network to the MCTRL
   interface. */

/* mctrl_devnet_status()
   Return status information for the linked control network */

/* mctrl_devnet_add()
   Add a movement device to the specified control network */

/* mctrl_devnet_del()
   Remove the specified movement device from the specified 
   control network */

/* mctrl_devnet_en()
   Enable/Disable all movement devices on the specified
   control network */

/* mctrl_devnet_dev_status()
   Return status information for all movement devices
   on the specified control network */

/* -------------------------------------------------------------------------- */
/*  MCTRL Device ------------------------------------------------------------ */
/* -------------------------------------------------------------------------- */

/* mctrl_dev_en()
   Enable/Disable the specified movement device.

/* mctrl_dev_status()
   Return the status of the specified movement devices. */

/* -------------------------------------------------------------------------- */
/*  MCTRL Positioning ------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* mctrl_poslr_check()
   Return the left/right position of the system (e.g. mount) */

/* mctrl_poslr_cal()
   Calibrate the left/right positioning of the system */

/* mctrl_poslr_swingl()
   Swing the system left by the specified amount */
   
/* mctrl_poslr_swingr()
   Swing the system right by the specified amount*/

/* mctrl_posud_check()
   Return the up/down position of the system (e.g. mount) */

/* mctrl_posud_cal()
   Calibrate the up/down positioning of the system */

/* mctrl_posud_moveu
   Move the system up by the specified amount */

/* mctrl_posud_moved
   Move the system down by the specified amount */

/* -------------------------------------------------------------------------- */
/*  MCTRL Function Check ---------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* mctrl_ibit()
   Perform a function check for the movement system */

   
