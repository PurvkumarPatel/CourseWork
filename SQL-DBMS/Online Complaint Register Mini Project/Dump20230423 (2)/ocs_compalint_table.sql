-- MySQL dump 10.13  Distrib 8.0.32, for Win64 (x86_64)
--
-- Host: localhost    Database: ocs
-- ------------------------------------------------------
-- Server version	8.0.32

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `compalint_table`
--

DROP TABLE IF EXISTS `compalint_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `compalint_table` (
  `COMPALINT_ID` int NOT NULL,
  `COM_DATE` datetime DEFAULT NULL,
  `COM_ADDRESS` varchar(255) DEFAULT NULL,
  `COM_DES` varchar(255) DEFAULT NULL,
  `COM_STATUS` varchar(45) DEFAULT NULL,
  `Zone_ID` int DEFAULT NULL,
  `Department_ID` int DEFAULT NULL,
  `User_ID` int DEFAULT NULL,
  `O_ID` int DEFAULT NULL,
  PRIMARY KEY (`COMPALINT_ID`),
  KEY `Zone_ID` (`Zone_ID`),
  KEY `Department_ID` (`Department_ID`),
  KEY `User_ID` (`User_ID`),
  KEY `O_ID` (`O_ID`),
  CONSTRAINT `compalint_table_ibfk_1` FOREIGN KEY (`Zone_ID`) REFERENCES `zone_table` (`ZONE_ID`),
  CONSTRAINT `compalint_table_ibfk_2` FOREIGN KEY (`Department_ID`) REFERENCES `d_table` (`D_ID`),
  CONSTRAINT `compalint_table_ibfk_3` FOREIGN KEY (`User_ID`) REFERENCES `user_table` (`USER_ID`),
  CONSTRAINT `compalint_table_ibfk_4` FOREIGN KEY (`O_ID`) REFERENCES `officer_table` (`OFFICER_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-04-23 11:58:35
