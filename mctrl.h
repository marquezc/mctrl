/* mctrl.h - Motor Control Header File */

#ifndef MCTRL_H
#define MCTRL_H

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
#define MAX_DEVICES 128 // Maximum # of devices that may be attached to a net.

/* -------------------------------------------------------------------------- */
/*  Program Files and Path Information -------------------------------------- */
/* -------------------------------------------------------------------------- */


const char *mctrl_subfolder = "/mctrl";
const char *devnet_subfolder = "/devnet";
const char *device_subfolder = "/device";

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
  int state; // MCU {ON, OFF};
} Mcu;

typedef struct mctrl
{
  unsigned int id; // Unique [integer] Mcu identifier > 0;
  char name[MAX_NAME]; // MCTRL name;
  char desc[MAX_DESC]; // MCTRL description;
  unsigned int ip; // MCTRL IP address;
  char path[MAX_PATH]; // MCTRL profile path;
  int state; // MCTRL node {ON, OFF};
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
  int state; // Interface {ON, OFF};
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

int mctrl_interface_status (Iface *m_iface);

/* mctrl_print_interface_info()
   Print interface information to STDOUT */

void mctrl_print_interface_info (Iface *m_iface);

/* -------------------------------------------------------------------------- */
/*  MCTRL Device Network ---------------------------------------------------- */
/* -------------------------------------------------------------------------- */

typedef struct devnet
{
  unsigned int id; // Unique [integer] identifier > 0;
  char name[MAX_NAME]; // Device network name;
  char desc[MAX_DESC]; // Device network description;
  char path[MAX_PATH]; // Device network profile path;
  unsigned int mctrl_id; // Identifier of MCTRL node network belongs to;
  unsigned int devices[MAX_DEVICES]; // Identifiers of attached devices;
  int state; // State of devnet {ON, OFF};
} Devnet;

/* mctrl_devnet_new()
   Create a new device control network for movement system.
   Return devnet ID > 0 on success. Return -1 on failure. */

int mctrl_devnet_new (Devnet *m_devnet);

/* mctrl_devnet_del()
   Remove the specified device control network.
   Return 1 on success. Return -1 on failure. */

int mctrl_devnet_del (Devnet *m_devnet);

/* mctrl_devnet_clr()
   Remove all devices from the specified control network.
   Return 1 on success. Return -1 on failure. */

int mctrl_devnet_clr (Devnet *m_devnet);

/* mctrl_devnet_en()
   Enable or disable the specified device control network.
   Return new state of the device control network {ON, OFF}. */

int mctrl_devnet_en (Devnet *m_devnet);

/* mctrl_print_devnet_info 
   Print devicenet information to STDOUT */

void mctrl_print_devnet_info (Devnet *m_devnet);

/* mctrl_devnet_add_device()
   Add a movement device to the specified control network.
   Return 1 on success. Return 0 on failure. */

int mctrl_devnet_add_device (Devnet *m_devnet, Device *m_device);
   
/* mctrl_devnet_del_device()
   Remove the specified movement device from the device control network.
   Return 1 on success. Return 0 on failure. */

int mctrl_devnet_del_device (Devnet *m_devnet, Device *m_device);

/* -------------------------------------------------------------------------- */
/*  MCTRL Device ------------------------------------------------------------ */
/* -------------------------------------------------------------------------- */

typedef struct device
{
  unsigned int id; // Unique [integer] identifier > 0;
  char name[MAX_NAME]; // Device name;
  char desc[MAX_DESC]; // Device description;
  char path[MAX_PATH]; // Device profile path;
  unsigned int net[MAX_NETWORKS]; // Identifiers of attached device networks;
  unsigned int type; // Device type flag byte (see defines in General section);
} Device;

/* mctrl_device_new()
   Create a new movement device profile.
   Return devnet ID > 0 on success. Return -1 on failure. */

int mctrl_device_new (Device *m_device);

/* mctrl_device_del()
   Remove the specifed movement device.
   Return 1 on success. Return -1 on failure. */

int mctrl_device_del (Device *m_device);

/* mctrl_device_en()
   Enable/Disable the specified movement device on the
   given control network.
   Return 1 on success. Return 0 on failure. */

int mctrl_device_en (Devnet *m_devnet, Device *m_device);

/* mctrl_dev_status()
   Return the status of the specified movement devices. */

int mctrl_device_status (Devnet *m_devnt, Device *m_device);

/* mctrl_print_device_info()
   Print device information to STDOUT */

void mctrl_print_device_info (Device *m_device);


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

#endif
