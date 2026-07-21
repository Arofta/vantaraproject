-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jul 20, 2026 at 12:08 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ventara`
--

-- --------------------------------------------------------

--
-- Table structure for table `player_accounts`
--

CREATE TABLE `player_accounts` (
  `account_id` int(11) NOT NULL,
  `account_name` varchar(24) NOT NULL,
  `account_discord_id` varchar(20) NOT NULL,
  `account_password` varchar(60) NOT NULL,
  `account_verify` mediumint(11) NOT NULL,
  `account_recovery` mediumint(11) NOT NULL,
  `account_last_online` datetime NOT NULL,
  `account_register_date` datetime NOT NULL DEFAULT current_timestamp(),
  `banned_status` tinyint(11) NOT NULL DEFAULT 0,
  `banned_issuer` varchar(24) NOT NULL,
  `banned_reason` varchar(60) NOT NULL,
  `banned_duration` bigint(11) NOT NULL,
  `banned_time` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `player_accounts`
--

INSERT INTO `player_accounts` (`account_id`, `account_name`, `account_discord_id`, `account_password`, `account_verify`, `account_recovery`, `account_last_online`, `account_register_date`, `banned_status`, `banned_issuer`, `banned_reason`, `banned_duration`, `banned_time`) VALUES
(1, 'TreetMe', '1022436604322783242', '$2b$12$Xrkf.7GQa.xNA1q5eNXB9OD9gI.mTOzX6D2E.w2XxlYWNhhis75xC', -1, -1, '2026-07-19 17:35:18', '2026-06-03 10:38:25', 0, '', '', 0, '0000-00-00 00:00:00'),
(2, 'Developer', '0', '', 160074, -1, '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, '', '', 0, '0000-00-00 00:00:00'),
(3, 'PhiBi', '952110585972142110', '', 172323, -1, '0000-00-00 00:00:00', '2026-06-10 17:35:30', 0, '', '', 0, '0000-00-00 00:00:00'),
(4, 'Dewa', '2', '', 731459, -1, '0000-00-00 00:00:00', '2026-06-10 17:39:37', 0, '', '', 0, '0000-00-00 00:00:00'),
(5, 'Developer2', '1022', '$2b$12$9Qf.5P29RGYHiirmOoNEnugT2fYFOgBJK5uk0Yr.ryKIYsHSNnQp6', -1, -1, '2026-06-25 16:17:25', '2026-06-10 19:02:52', 0, '', '', 0, '0000-00-00 00:00:00');

-- --------------------------------------------------------

--
-- Table structure for table `player_characters`
--

CREATE TABLE `player_characters` (
  `char_id` int(11) NOT NULL,
  `char_account_id` int(11) NOT NULL,
  `char_ucp` varchar(24) NOT NULL,
  `char_name` varchar(24) NOT NULL,
  `char_register_date` datetime NOT NULL DEFAULT current_timestamp(),
  `char_last_online` datetime NOT NULL DEFAULT current_timestamp(),
  `char_last_exit` int(11) NOT NULL DEFAULT 0,
  `char_pos_x` float NOT NULL DEFAULT 0,
  `char_pos_y` float NOT NULL DEFAULT 0,
  `char_pos_z` float NOT NULL DEFAULT 0,
  `char_pos_a` float NOT NULL DEFAULT 0,
  `char_health` float NOT NULL DEFAULT 100,
  `char_armour` int(11) NOT NULL DEFAULT 0,
  `char_admin_name` varchar(24) NOT NULL,
  `char_admin_level` int(11) NOT NULL DEFAULT 0,
  `char_level` int(11) NOT NULL DEFAULT 1,
  `char_money` int(11) NOT NULL DEFAULT 10000,
  `char_bank_money` int(11) NOT NULL DEFAULT 50000,
  `char_skin` int(11) NOT NULL DEFAULT 250,
  `char_dob` varchar(11) NOT NULL,
  `char_origin` int(11) NOT NULL,
  `char_gender` int(11) NOT NULL,
  `char_weight` int(11) NOT NULL,
  `char_height` int(11) NOT NULL,
  `char_domicile` int(11) NOT NULL,
  `char_virtual_world` int(11) NOT NULL DEFAULT 0,
  `char_interior` int(11) NOT NULL DEFAULT 0,
  `char_job` int(11) NOT NULL DEFAULT 0,
  `char_faction` int(11) NOT NULL DEFAULT 0,
  `char_faction_rank` int(11) NOT NULL DEFAULT 0,
  `char_family` int(11) NOT NULL DEFAULT -1,
  `char_family_rank` int(11) NOT NULL DEFAULT 0,
  `char_injured` int(11) NOT NULL DEFAULT 0,
  `char_injury_time` int(11) NOT NULL DEFAULT -1,
  `char_hunger` float NOT NULL DEFAULT 50,
  `char_thirst` float NOT NULL DEFAULT 50,
  `char_stress` float NOT NULL DEFAULT 0,
  `char_playtime` int(11) NOT NULL DEFAULT 0,
  `char_vip` int(11) NOT NULL DEFAULT 0,
  `char_vip_expiry` int(11) NOT NULL DEFAULT 0,
  `char_guardian` int(11) NOT NULL DEFAULT 0,
  `char_guardian_expiry` int(11) NOT NULL DEFAULT 0,
  `char_server_master` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `player_characters`
--

INSERT INTO `player_characters` (`char_id`, `char_account_id`, `char_ucp`, `char_name`, `char_register_date`, `char_last_online`, `char_last_exit`, `char_pos_x`, `char_pos_y`, `char_pos_z`, `char_pos_a`, `char_health`, `char_armour`, `char_admin_name`, `char_admin_level`, `char_level`, `char_money`, `char_bank_money`, `char_skin`, `char_dob`, `char_origin`, `char_gender`, `char_weight`, `char_height`, `char_domicile`, `char_virtual_world`, `char_interior`, `char_job`, `char_faction`, `char_faction_rank`, `char_family`, `char_family_rank`, `char_injured`, `char_injury_time`, `char_hunger`, `char_thirst`, `char_stress`, `char_playtime`, `char_vip`, `char_vip_expiry`, `char_guardian`, `char_guardian_expiry`, `char_server_master`) VALUES
(1, 1, 'TreetMe', 'Rimuru_Tempest', '2026-06-24 03:59:04', '2026-07-19 17:35:18', 1784457318, 1684.72, 1460.97, 10.7694, 357.375, 100, 0, 'Rimuru', 7, 100, 10000, 50000, 2, '02-03-1989', 87, 1, 61, 167, 2, 0, 0, 0, 0, 0, -1, 0, 0, 0, 100, 100, 0, 31871, 5, 1845466200, 0, 0, 1),
(2, 1, 'TreetMe', 'Michael_Adam', '2026-06-11 20:42:41', '2026-06-24 17:24:26', 1782296666, 2059.32, -2311.18, 16.125, 204.89, 96.7, 0, 'TreetMe', 7, 1, 10000, 50000, 288, '05-02-2001', 0, 1, 68, 173, 0, 0, 0, 0, 0, 0, -1, 0, 1, 1050, 57.7, 51.02, 2, 6, 0, 0, 0, 0, 0),
(3, 1, 'TreetMe', 'Budiman_Sudjatmiko', '2026-06-06 11:27:31', '2026-07-08 13:27:50', 1783492070, -1437.52, -287.376, 14, 60.1712, 29.34, 100, 'TreetMe', 7, 1, 10000, 50000, 299, '21-06-1961', 0, 1, 63, 168, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 35.44, 24.09, 76.5, 6075, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `player_inventory`
--

CREATE TABLE `player_inventory` (
  `inv_owner_id` int(11) NOT NULL,
  `inv_slot_id` int(11) NOT NULL,
  `inv_item_id` int(11) NOT NULL,
  `inv_quantity` int(11) NOT NULL,
  `inv_metadata` varchar(128) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `player_inventory`
--

INSERT INTO `player_inventory` (`inv_owner_id`, `inv_slot_id`, `inv_item_id`, `inv_quantity`, `inv_metadata`) VALUES
(1, 0, 0, 1, ''),
(3, 0, 0, 1, ''),
(3, 1, 0, 1, '');

-- --------------------------------------------------------

--
-- Table structure for table `player_vehicles`
--

CREATE TABLE `player_vehicles` (
  `vehicle_id` int(11) NOT NULL,
  `vehicle_owner_id` int(11) NOT NULL,
  `vehicle_model_id` int(11) NOT NULL,
  `vehicle_color_1` int(11) NOT NULL DEFAULT 0,
  `vehicle_color_2` int(11) NOT NULL DEFAULT 0,
  `vehicle_paintjob` int(11) NOT NULL DEFAULT -1,
  `vehicle_components` varchar(128) DEFAULT NULL,
  `vehicle_pos_x` float NOT NULL DEFAULT 0,
  `vehicle_pos_y` float NOT NULL DEFAULT 0,
  `vehicle_pos_z` float NOT NULL DEFAULT 0,
  `vehicle_pos_a` float NOT NULL DEFAULT 0,
  `vehicle_health` float NOT NULL DEFAULT 1000,
  `vehicle_fuel` float NOT NULL DEFAULT 100,
  `vehicle_locked` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `player_weapon`
--

CREATE TABLE `player_weapon` (
  `weap_id` int(11) NOT NULL,
  `weap_owner_id` int(11) NOT NULL,
  `weap_type` int(11) NOT NULL,
  `weap_condition` float NOT NULL DEFAULT 100,
  `weap_grade` int(11) NOT NULL,
  `weap_ammo` int(11) NOT NULL,
  `weap_serial` varchar(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `player_accounts`
--
ALTER TABLE `player_accounts`
  ADD PRIMARY KEY (`account_id`),
  ADD UNIQUE KEY `SECONDARY` (`account_name`),
  ADD UNIQUE KEY `THIRD` (`account_discord_id`);

--
-- Indexes for table `player_characters`
--
ALTER TABLE `player_characters`
  ADD PRIMARY KEY (`char_id`),
  ADD KEY `SECONDARY` (`char_account_id`);

--
-- Indexes for table `player_inventory`
--
ALTER TABLE `player_inventory`
  ADD PRIMARY KEY (`inv_owner_id`,`inv_slot_id`);

--
-- Indexes for table `player_vehicles`
--
ALTER TABLE `player_vehicles`
  ADD PRIMARY KEY (`vehicle_id`),
  ADD KEY `SECONDARY` (`vehicle_owner_id`);

--
-- Indexes for table `player_weapon`
--
ALTER TABLE `player_weapon`
  ADD PRIMARY KEY (`weap_id`),
  ADD KEY `SECONDARY` (`weap_owner_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `player_accounts`
--
ALTER TABLE `player_accounts`
  MODIFY `account_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `player_characters`
--
ALTER TABLE `player_characters`
  MODIFY `char_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `player_vehicles`
--
ALTER TABLE `player_vehicles`
  MODIFY `vehicle_id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `player_weapon`
--
ALTER TABLE `player_weapon`
  MODIFY `weap_id` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
