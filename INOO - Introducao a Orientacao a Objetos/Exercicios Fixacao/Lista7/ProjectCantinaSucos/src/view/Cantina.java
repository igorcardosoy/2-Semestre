package view;

import model.Suco;
import model.Polpa;

import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

public class Cantina {

    private static List<Suco> sucos;
    private static List<Polpa> polpas;

    private static int vendaTotal;
    private static double lucroTotal;

    private static Polpa polpaPrin;
    private static Polpa polpaSec;

    public Cantina() {
        sucos = new ArrayList<>(5);
        polpas = new ArrayList<>(5);
    }

    public static void run() {
        String answer = "";
        String title = "Cantina de Sucos";

        Object options[] = {"Adicionar Polpa", "Adicionar Suco", "Vender Suco", "Ver Venda Total", "Ver Lucro Total", "Sair"};

        JOptionPane.showMessageDialog(null, "Bem vindo a Cantina de Sucos!", title, JOptionPane.INFORMATION_MESSAGE);

        do {
            answer = (String) JOptionPane.showInputDialog(null, "O que deseja?", title, JOptionPane.QUESTION_MESSAGE, null, options, options[0]);

            if (!answer.equals("Sair")) {
                switch (answer) {
                    case "Adicionar Polpa":
                        String sabor = JOptionPane.showInputDialog(null, "Qual o sabor da polpa?", title, JOptionPane.QUESTION_MESSAGE);
                        double valor = Double.parseDouble(JOptionPane.showInputDialog(null, "Qual o valor da polpa?", title, JOptionPane.QUESTION_MESSAGE));
                        adicionarPolpa(sabor, valor);
                        break;
                    case "Adicionar Suco":

                        if (!polpas.isEmpty() && polpas.size() >= 2)
                        {
                            Object sabores[] = new Object[polpas.size()];
                            for (int i = 0; i < polpas.size(); i++) {
                                sabores[i] = polpas.get(i).getSabor();
                            }

                            String polpa1, polpa2;

                            polpa1 = (String) JOptionPane.showInputDialog(null, "Qual o sabor da polpa principal?", title, JOptionPane.QUESTION_MESSAGE, null, sabores, sabores[0]);
                            polpa2 = (String) JOptionPane.showInputDialog(null, "Qual o sabor da polpa secundária?", title, JOptionPane.QUESTION_MESSAGE, null, sabores, sabores[0]);

                            polpas.forEach(polpa -> {
                                if (polpa.getSabor().equals(polpa1)) {
                                    polpaPrin = polpa;
                                }
                                if (polpa.getSabor().equals(polpa2)) {
                                    polpaSec = polpa;
                                }
                            });

                            adicionarSuco(polpaPrin, polpaSec);
                        } else {
                            JOptionPane.showMessageDialog(null, "Não há polpas suficientes para fazer um suco!", title, JOptionPane.ERROR_MESSAGE);
                        }
                        break;
                    case "Vender Suco":
                        if (sucos.size() > 0) {
                            String[] sucosString = new String[sucos.size()];
                            for (int i = 0; i < sucos.size(); i++) {
                                sucosString[i] = sucos.get(i).toString();
                            }
                            int index = JOptionPane.showOptionDialog(null, "Qual suco deseja vender?", title, JOptionPane.DEFAULT_OPTION, JOptionPane.QUESTION_MESSAGE, null, sucosString, sucosString[0]);
                            venderSuco(index);
                        } else {
                            JOptionPane.showMessageDialog(null, "Não há sucos para vender!", title, JOptionPane.INFORMATION_MESSAGE);
                        }
                        break;
                    case "Ver Venda Total":
                        JOptionPane.showMessageDialog(null, "A venda total é de R$" + vendaTotal, title, JOptionPane.INFORMATION_MESSAGE);
                        break;
                    case "Ver Lucro Total":
                        JOptionPane.showMessageDialog(null, "O lucro total é de R$" + lucroTotal, title, JOptionPane.INFORMATION_MESSAGE);
                        break;
                }
            }
            } while (answer != "Sair") ;
    }

    private static void adicionarPolpa(String sabor, double valor) {
        polpas.add(new Polpa(sabor, valor));
    }

    private static void adicionarSuco(Polpa sabor1, Polpa sabor2){

        if (polpas.size() >= 2)
        {
            polpas.forEach(polpa -> {
                if (polpa.getSabor().equals(sabor1)) {
                    polpaPrin = polpa;
                }
                if (polpa.getSabor().equals(sabor2)) {
                    polpaSec = polpa;
                }
            });
        }

        Suco suco = new Suco(polpaPrin, polpaSec);
        sucos.add(suco);
    }

    private static void venderSuco(int index) {
        Suco suco = sucos.get(index);
        vendaTotal += suco.getPreco();
        lucroTotal += suco.getLucro();
        sucos.remove(index);
    }

}