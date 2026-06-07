-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 06, 2026 at 09:01 AM
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
-- Database: `Vantara`
--

-- --------------------------------------------------------

--
-- Table structure for table `player_accounts`
--

CREATE TABLE `player_accounts` (
  `account_id` int(11) NOT NULL,
  `account_name` varchar(24) NOT NULL,
  `account_discord_id` int(11) NOT NULL,
  `account_password` varchar(60) NOT NULL,
  `account_verify` int(11) NOT NULL,
  `account_recovery` int(11) NOT NULL,
  `account_last_online` datetime NOT NULL,
  `account_register_date` datetime NOT NULL,
  `banned_status` int(11) NOT NULL DEFAULT 0,
  `banned_issuer` varchar(24) NOT NULL,
  `banned_reason` varchar(60) NOT NULL,
  `banned_duration` int(11) NOT NULL,
  `banned_time` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `player_accounts`
--

INSERT INTO `player_accounts` (`account_id`, `account_name`, `account_discord_id`, `account_password`, `account_verify`, `account_recovery`, `account_last_online`, `account_register_date`, `banned_status`, `banned_issuer`, `banned_reason`, `banned_duration`, `banned_time`) VALUES
(1, 'TreetMe', 0, '$2b$12$rWT6gweD/skenjQwHhkEzefa/9XvF7kHCnll3k1ANiIOjCal3u1Hm', -1, -1, '0000-00-00 00:00:00', '2026-06-03 10:38:25', 0, '', '', 0, '0000-00-00 00:00:00');

-- --------------------------------------------------------

--
-- Table structure for table `player_characters`
--

CREATE TABLE `player_characters` (
  `char_id` int(11) NOT NULL,
  `char_account_id` int(11) NOT NULL,
  `char_ucp` varchar(24) NOT NULL,
  `char_name` varchar(24) NOT NULL,
  `char_register_date` datetime NOT NULL,
  `char_last_online` datetime NOT NULL,
  `char_last_exit` int(11) NOT NULL,
  `char_pos_x` float NOT NULL DEFAULT 0,
  `char_pos_y` float NOT NULL DEFAULT 0,
  `char_pos_z` float NOT NULL DEFAULT 0,
  `char_pos_a` float NOT NULL DEFAULT 0,
  `char_health` float NOT NULL DEFAULT 100,
  `char_armour` int(11) NOT NULL DEFAULT 0,
  `char_level` int(11) NOT NULL,
  `char_money` int(11) NOT NULL DEFAULT 10000,
  `char_bank_money` int(11) NOT NULL DEFAULT 50000,
  `char_skin` int(11) NOT NULL DEFAULT 2,
  `char_dob` varchar(11) NOT NULL,
  `char_origin` int(11) NOT NULL,
  `char_gender` int(11) NOT NULL,
  `char_weight` int(11) NOT NULL,
  `char_height` int(11) NOT NULL,
  `char_domicile` int(11) NOT NULL,
  `char_hunger` float NOT NULL,
  `char_thirst` float NOT NULL,
  `char_stress` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `player_characters`
--

INSERT INTO `player_characters` (`char_id`, `char_account_id`, `char_ucp`, `char_name`, `char_register_date`, `char_last_online`, `char_last_exit`, `char_pos_x`, `char_pos_y`, `char_pos_z`, `char_pos_a`, `char_health`, `char_armour`, `char_level`, `char_money`, `char_bank_money`, `char_skin`, `char_dob`, `char_origin`, `char_gender`, `char_weight`, `char_height`, `char_domicile`, `char_hunger`, `char_thirst`, `char_stress`) VALUES
(1, 1, 'TreetMe', 'Joko_Widodo', '2026-06-06 11:27:31', '2026-06-06 11:27:31', 0, 0, 0, 0, 0, 100, 0, 1, 10000, 50000, 250, '21-06-1961', 0, 1, 63, 168, 1, 50, 50, 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `player_accounts`
--
ALTER TABLE `player_accounts`
  ADD PRIMARY KEY (`account_id`);

--
-- Indexes for table `player_characters`
--
ALTER TABLE `player_characters`
  ADD PRIMARY KEY (`char_id`),
  ADD KEY `SECONDARY` (`char_account_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `player_accounts`
--
ALTER TABLE `player_accounts`
  MODIFY `account_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `player_characters`
--
ALTER TABLE `player_characters`
  MODIFY `char_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
