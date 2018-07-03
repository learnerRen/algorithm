package exp6;
import java.util.Random;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
public class logic {
	int data[][]=new int[4][3];//the first three rows stand for the graph;
	//row4 column1 the depth, row4 column2 weight row4 column3 action
	//action 1,2,3 4 stands for up down left right
	int ans[][]=new int[3][3];
	Comparator<int[][]> cmp=new Comparator<int[][]>() {
		@Override
		public int compare(int[][] a1, int[][] a2) {
			// TODO 自动生成的方法存根
			return a1[3][1]-a2[3][1];
		}
    };
    Queue<int[][]> q=new PriorityQueue<>(cmp);
	public void initial(){
		q.clear();
		int[] num=new int[9];
		for(int i=0;i<9;i++)
		{
	        num[i] = new Random().nextInt(9);
	            for(int j=0;j<i;j++)
	            {
	                if(num[i]==num[j])
	                {
	                    i--;  
	                   break;  
	                }  
	            }  
	      }
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<3;++j)
			{
				this.data[i][j]=num[i*3+j];
			}
		}
		this.ans[0][0]=1;
		this.ans[0][1]=2;
		this.ans[0][2]=3;
		this.ans[1][0]=8;
		this.ans[1][1]=0;
		this.ans[1][2]=4;
		this.ans[2][0]=7;
		this.ans[2][1]=6;
		this.ans[2][2]=5;
		this.data[3][0]=0;
		int count=0;
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<3;++j)
			{
				if(this.data[i][j]!=this.ans[i][j])
					++count;
			}
		}
		data[3][1]=data[3][0]+count;
		data[3][2]=0;
		int[][] d=new int[4][3];
		d=data;
		q.add(d);
	}
	public boolean AbleToWin(int[][] data) 
	{
		int now[]=new int[9];
		for(int i=0;i<3;++i)
		{
			now[i]=data[0][i];
		}
		now[3]=data[1][2];
		now[4]=data[2][2];
		now[5]=data[2][1];
		now[6]=data[2][0];
		now[7]=data[1][0];
		now[8]=0;
		int judge = 0;
		for(int i=0; i<8; i++)
		{
			if(now[i]==0)
				continue;
			for(int j=0; j<i; j++)
			{
				if(now[j]==0)
					continue;
				if(now[i]<now[j])
					judge++;
			}
		}
		return judge%2==0;
	}
	
	public int next()
	{
		boolean t=true;
		int d[][]=new int[4][3];
		d=q.remove();
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<3;++j)
				if(d[i][j]!=ans[i][j])
				{
					t=false;
					break;
				}
		}
		if(t)
		{
			System.out.println("this is the answer");
			return 1;
		}
		int possible_action[][][]=new int[3][3][4];
		possible_action[0][0][0]=0;
		possible_action[0][0][1]=1;
		possible_action[0][0][2]=0;
		possible_action[0][0][3]=1;
		
		possible_action[0][1][0]=0;
		possible_action[0][1][1]=1;
		possible_action[0][1][2]=1;
		possible_action[0][1][3]=1;
		
		possible_action[0][2][0]=0;
		possible_action[0][2][1]=1;
		possible_action[0][2][2]=1;
		possible_action[0][2][3]=0;
		
		possible_action[1][0][0]=1;
		possible_action[1][0][1]=1;
		possible_action[1][0][2]=0;
		possible_action[1][0][3]=1;
		
		possible_action[1][1][0]=1;
		possible_action[1][1][1]=1;
		possible_action[1][1][2]=1;
		possible_action[1][1][3]=1;
		
		possible_action[1][2][0]=1;
		possible_action[1][2][1]=1;
		possible_action[1][2][2]=1;
		possible_action[1][2][3]=0;
		
		possible_action[2][0][0]=1;
		possible_action[2][0][1]=0;
		possible_action[2][0][2]=0;
		possible_action[2][0][3]=1;
		
		possible_action[2][1][0]=1;
		possible_action[2][1][1]=0;
		possible_action[2][1][2]=1;
		possible_action[2][1][3]=1;
		
		possible_action[2][2][0]=1;
		possible_action[2][2][1]=0;
		possible_action[2][2][2]=1;
		possible_action[2][2][3]=0;
		
		int loc[]=new int[2];
		for(int i=0;i<3;++i)
		{
			for(int j=0;j<3;++j)
			{
				if(d[i][j]==0)
				{
					loc[0]=i;
					loc[1]=j;
				}
			}
		}
		System.out.println(d[3][2]);
		if(d[3][2]==1)
			possible_action[loc[0]][loc[1]][1]=0;
		if(d[3][2]==2)
			possible_action[loc[0]][loc[1]][0]=0;
		if(d[3][2]==3)
			possible_action[loc[0]][loc[1]][3]=0;
		if(d[3][2]==4)
			possible_action[loc[0]][loc[1]][2]=0;
		if(possible_action[loc[0]][loc[1]][0]!=0)
		{
			int d1[][]=d;
			int count=0;
			++d1[3][0];
			System.out.println(loc[0]);
			System.out.println(loc[1]);
			int a=d1[loc[0]][loc[1]+1];
			d1[loc[0]][loc[1]+1]=0;
			d1[loc[0]][loc[1]]=a;
			for(int i=0;i<3;++i)
			{
				for(int j=0;j<3;++j)
					if(d[i][j]!=ans[i][j])
					{
						++count;
					}
			}
			if(count==0)
			{
				System.out.println("this is the answer.");
				return 1;
			}
			d1[3][1]=d1[3][0]+count;
			d1[3][2]=1;
			q.add(d1);
		}
		if(possible_action[loc[0]][loc[1]][1]!=0)
		{
			int d1[][]=d;
			int count=0;
			++d1[3][0];
			int a=d1[loc[0]][loc[1]-1];
			d1[loc[0]][loc[1]-1]=0;
			d1[loc[0]][loc[1]]=a;
			for(int i=0;i<3;++i)
			{
				for(int j=0;j<3;++j)
					if(d[i][j]!=ans[i][j])
					{
						++count;
					}
			}
			if(count==0)
			{
				System.out.println("this is the answer.");
				return 1;
			}
			d1[3][1]=d1[3][0]+count;
			d1[3][2]=2;
			q.add(d1);
		}
		if(possible_action[loc[0]][loc[1]][2]!=0)
		{
			int d1[][]=d;
			int count=0;
			++d1[3][0];
			int a=d1[loc[0]-1][loc[1]];
			d1[loc[0]-1][loc[1]]=0;
			d1[loc[0]][loc[1]]=a;
			for(int i=0;i<3;++i)
			{
				for(int j=0;j<3;++j)
					if(d[i][j]!=ans[i][j])
					{
						++count;
					}
			}
			if(count==0)
			{
				System.out.println("this is the answer.");
				return 1;
			}
			d1[3][1]=d1[3][0]+count;
			d1[3][2]=3;
			q.add(d1);
		}
		if(possible_action[loc[0]][loc[1]][3]!=0)
		{
			int d1[][]=d;
			int count=0;
			++d1[3][0];
			for(int i=0;i<3;++i)
			{
				for(int j=0;j<3;++j)
					if(d[i][j]!=ans[i][j])
					{
						++count;
					}
			}
			if(count==0)
			{
				System.out.println("this is the answer.");
				return 1;
			}
			int a=d1[loc[0]][loc[1]+1];
			d1[loc[0]][loc[1]+1]=0;
			d1[loc[0]][loc[1]]=a;
			d1[3][1]=d1[3][0]+count;
			d1[3][2]=4;
			q.add(d1);
		}
		System.out.println("There is no answear, please initialize again.");	
		return 0;
	}
	public static void main(String args[]){
		logic l = new logic();
		l.initial();
		JPanel p=new JPanel();
		p.setSize(400,400);
		JButton b1=new JButton("wait for initialize");
		JButton b2=new JButton("wait for initialize");
		JButton b3=new JButton("wait for initialize");
		JButton b4=new JButton("wait for initialize");
		JButton b5=new JButton("wait for initialize");
		JButton b6=new JButton("wait for initialize");
		JButton b7=new JButton("wait for initialize");
		JButton b8=new JButton("wait for initialize");
		JButton b9=new JButton("wait for initialize");
		JButton init=new JButton("initialize");
		JButton Next=new JButton("Next");
		JTextField j=new JTextField(30);
		p.add(b1);
		p.add(b2);
		p.add(b3);
		p.add(b4);
		p.add(b5);
		p.add(b6);
		p.add(b7);
		p.add(b8);
		p.add(b9);
		p.add(init);
		p.add(Next);
		p.add(j);
		JFrame f=new JFrame();
		f.add(p);
		f.setSize(400, 400);
		f.setVisible(true);

		ActionListener ll1=new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO 自动生成的方法存根
				l.initial();
				b1.setText("         "+l.data[0][0]+"         ");
				b2.setText("         "+l.data[0][1]+"         ");
				b3.setText("         "+l.data[0][2]+"         ");
				b4.setText("         "+l.data[1][0]+"         ");
				b5.setText("         "+l.data[1][1]+"         ");
				b6.setText("         "+l.data[1][2]+"         ");
				b7.setText("         "+l.data[2][0]+"         ");
				b8.setText("         "+l.data[2][1]+"         ");
				b9.setText("         "+l.data[2][2]+"         ");
				if(!l.AbleToWin(l.data))
					j.setText("there is no answer");
				else
					j.setText("There will be answer");
			}
			
		};
		init.addActionListener(ll1);
		ActionListener ll2=new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO 自动生成的方法存根
				l.next();
			}
			
		};
		Next.addActionListener(ll2);
		/*
	    boolean flag=true;
	    while(flag)//initial button is push
	    {
	    	flag=false;
	    	l.q.clear();
	    	int d1[][]=new int[3][3];
			d1=l.data;
			l.q.add(d1);
			boolean flag2=true;
			if(l.AbleToWin(l.q.element()))
			{
				System.out.println("there is no result.");
				break;
			}
			while(flag2)//push next
			{
				l.next();
			}
	    }
	    */
	}
}
